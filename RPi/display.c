#include "output.h"

/**
	Function definition of setColour()

	Changes the console text output colour.

	Arguments: ANSI colour ID
	Return: none
*/
void setColour ( unsigned short id )
{
	fprintf( stdout, "%c[%d;1m", ESC, id );
}

/**
	Function definition of _clear()
	
	Clears the console text screen.
	
	Arguments: none
	Returns: none
*/
void _clear ( void )
{
	// Linux, UNIX, and Apple software console command
#if defined( __linux__ ) || defined( __unix__ ) || defined( __APPLE__ )
    system("clear");
#endif
    // Win32 and Win64 software console command
#if defined( _WIN32 ) || defined( _WIN64 )
    system("cls");
#endif
}

/**
	Function definition of drawMenu()

	Draws the console TUI ( text user interface ) depending on the set mode. Mode is defined by the
	"MODE" variable value.

	There are 3 "MODE" variable values that can be passed to the function:

		1. MODE = 0:
			
			"time_left" variable is ignored
			"fig" variable is ignored

			List of things drawn:
				- Intro field   ( "intro" variable )
				- List field    ( "list" variable )
				- Request field ( "request" variable )

		2. MODE = 1:

			"time_left" variable is ignored
			"fig" variable is printed out

			List of things drawn:
				- Figure field ( "fig" variable; added to the right side of the "list" field )
				- Timer field  ( "timer" variable; replaces the "request" field )

		3. MODE = 2:

			"time_left" variable is printed out
			"fig" variable is ignored

			List of things drawn:
				- Timer value ( "time_left" variable )

	Arguments:
		MODE      - defines what to draw
		fig       - the figure to draw
		time_left - time counter ( being counted in main() )

	Returns: none
*/
void draw
(
	const unsigned short MODE,
	char fig[][ FIG_AREA_WIDTH ],
	int time_left
)
{
	int
		i;
	char
		intro[ 7 ][ LIST_AREA_WIDTH + FIG_AREA_WIDTH ] =
		{
			"+-----------------------------------------------------------+\0",
			"|                                                           |\0",
			"|               The                                         |\0",
			"|                       figure                              |\0",
			"|                                  drawer                   |\0",
			"|                                                           |\0",
			"+-----------------------------------------------------------+\0"
		}, // The "intro" field contents

		list[ FIG_AREA_HEIGHT ][ LIST_AREA_WIDTH ] =
		{
			"+---------------------------------+\0",
			"|                                 |\0",
			"|    Figures:                     |\0",
			"|                                 |\0",
			"|        1. Rectangle             |\0",
			"|        2. Square                |\0",
			"|        3. Triangle              |\0",
			"|        4. Circle                |\0",
			"|        5. Horizontal line       |\0",
			"|        6. Intersecting lines    |\0",
			"|                                 |\0",
			"+---------------------------------+\0"
		}, // The "list" field contents

		request[ 7 ][ LIST_AREA_WIDTH + FIG_AREA_WIDTH ] =
		{
			"+-----------------------------------------------------------+\0",
			"|                                                           |\0",
			"|                   Enter the number                        |\0",
			"|               of figure to draw or                        |\0",
			"|              anything else to exit:                       |\0",
			"|                                                           |\0",
			"+-----------------------------------------------------------+\0"
		}, // The "request" field contents

		timer[ 7 ][ LIST_AREA_WIDTH + FIG_AREA_WIDTH ] =
		{
			"+-----------------------------------------------------------+\0",
			"|                                                           |\0",
			"|                     Seconds left                          |\0",
			"|                 until the figure                          |\0",
			"|                       disappears:                         |\0",
			"|                                                           |\0",
			"+-----------------------------------------------------------+\0"
		}; // The "timer" field contents

	fflush( stdout );

	// The figure is not chosen, only the menu appears
	if ( MODE == 0 )
	{
		_clear();

		// Drawing the "intro" field
		setColour( INTRO_AREA_COLOUR );
		for ( i = 0; i < 7; ++i )
		{
			fprintf( stdout, "\n  %s", intro[ i ] ); // Drawing the "intro" line
		}

		// Drawing the "list" field
		setColour( LIST_AREA_COLOUR );
		for ( i = 0; i < FIG_AREA_HEIGHT; ++i )
		{
			fprintf( stdout, "\n  %s", list[ i ] ); // Drawing the "list" line
		}

		// Drawing the "request" field
		setColour( BOTTOM_AREA_COLOUR );
		for ( i = 0; i < 7; ++i )
		{
			fprintf( stdout, "\n  %s", request[ i ] ); // Drawing the "request" line
		}

		// Replacing the cursor into the "request" box input field and setting its colour
		setColour( REQUEST_INPUT_AREA_COLOUR );		
		fprintf( stdout, "\033[25;41H\0" );
	}

	// The figure is chosen and it is being drawn. The "request" field is changed to the "timer"
	else if ( MODE == 1 )
	{
		// Drawing the "fig" field
		setColour( FIGURE_AREA_COLOUR );
		for ( i = 0; i < FIG_AREA_HEIGHT; ++i )
		{
			// Drawing the "fig" line
			fprintf(
				stdout,
				"\033[%d;40H%s\0",
				i + 9, fig[ i ]
			);
		}

		// Drawing the "timer" field
		setColour( BOTTOM_AREA_COLOUR );
		for ( i = 0; i < 7; ++i )
		{
			// Drawing the "timer" line
			fprintf(
				stdout,
				"\033[%d;3H%s\0",
				i + 21, timer[ i ]
			);
		}
	}
	
	// "time_left" variable is being counted down in the "timer" field
	else if ( MODE == 2 )
	{
		// Refreshing the timer value
		setColour( TIMER_OUTPUT_AREA_COLOUR );
		fprintf( stdout, "\033[25;41H%d\0", time_left );
	}

	fflush( stdout );
}