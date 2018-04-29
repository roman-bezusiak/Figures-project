#include "output.h"

/**
	Function definition of main()

	The main function of the program

	Arguments: none
	Return: 0
*/
int main ( void )
{
	char
		inp,                                      // User input variable ( Choise number )
		raw_inp[ 2 ],                             // User input variable ( Choise number + Enter )
		fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ]; // The figure string
	int
		i,                      // Loop counter ( stands for timer in seconds )
		fig_size =
			sizeof( char ) * FIG_AREA_HEIGHT * FIG_AREA_WIDTH, // Memory size of the "fig" variable 
			                                                   // ( bytes )
		raw_inp_size =
			sizeof( char ) * 2; // Memory size of the "raw_inp" variable ( bytes )
	bool
		end = false; // End of the algorithm flag

	// Main loop
	while ( !end )
	{
		draw( 0, fig, i ); // Drawing the menu

		fflush( stdin );                // Flushing the input stream
		fscanf( stdin, "%s", raw_inp ); // Getting the user input ( 2 keys )

		inp = raw_inp[ 0 ]; // Passing only the value of the first key pressed tothe "inp" variable

		memset( raw_inp, '\0', raw_inp_size ); // Cleaning the "raw_inp" variable
		memset( fig, FILL_SYMB, fig_size );    // Setting all "fig" variable values to "FILL_SYMB"
		                                       // constant value

		// Changing the "fig" variable to the chosen figure shape or ending the program algorithm
		switch ( inp )
		{
			case RECTANGLE: makeRectangle( fig ); break;
			case SQUARE:    makeSquare( fig );    break;
			case TRIANGLE:  makeTriangle( fig );  break;
			case CIRCLE:    makeCircle( fig );    break;
			case HLINE:     makeHLine( fig );     break;
			case XLINES:    makeXLines( fig );    break;
			default: end = true;
		}
		
		if ( !end )
		{
			i = RES_DELAY;

			draw( 1, fig, i ); // Displaying the chosen figure

			// Redrawing the chosen figure and counting down the time. The delay is defined by
			// "RES_DELAY" constant in seconds
			for ( i = RES_DELAY; i >= 1; --i ) 
			{	
				draw( 2, fig, i ); // Redrawing the window with updated timer value
				sleep( 1 );        // 1 second pause
			}
		}
	}
	
	_clear();                        // Clearing the screen
	fprintf( stdout, "%c[0m", ESC ); // Refreshing the console text colour
	
	return 0;
}