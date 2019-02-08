#include "output.h"

/*
	The drawing area ( two-dimensional char array "fig" ):

		CTTTTTTTTTTTTTTTTTTTTTTC\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		LDDDDDDDDDDDDDDDDDDDDDDR\0
		CBBBBBBBBBBBBBBBBBBBBBBC\0

	Legend:
		- C is a corner symbol
		- D is a drawing symbol
		- T B L R are top, bottom, left, and right border symbols respectively
		- \0 is the end of the line symbol ( one char )
*/

// Function definition of makeHLine()
void makeHLine ( char fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] )
{
	int
		i, j,                         // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		str_end     = FIG_AREA_WIDTH - 1, // The end of the drawing area ( including borders )
		middle      = ( int ) floor( sq_b_height / 2 ); // The middle height of the drawing area

	for ( i = 1; i < sq_b_height; ++i )
	{
		for ( j = 1; j < sq_b_width ; ++j )
		{
			// Drawing the line
			fig[ middle ][ j ] = HLINE_SYMB;

			// Horizontal border assingments
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Vertical border assingments
		fig[ i ][ 0 ]           = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ]  = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width ] = fig[ sq_b_height ][ 0 ] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height ][ sq_b_width ] = CORNER_SYMB;
}

// Function definition of makeXLines()
void makeXLines ( char fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] )
{
	int
		i, j, k,                      // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		str_end     = FIG_AREA_WIDTH - 1; // The end of the drawing area ( including borders )

	for ( i = 1, k = sq_b_width - 1; i < sq_b_height; ++i, k -= 2 )
	{
		// Drawing the lines
		fig[ i ][ sq_b_width - k ] = XLINES_SYMB; // Right-top to left-bottom
		fig[ i ][ k ]              = XLINES_SYMB; // Left-top to right-bottom

		// Horizontal border assingments
		for ( j = 1; j < sq_b_width ; ++j )
		{
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Vertical border assingments
		fig[ i ][ 0 ]          = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ] = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width ] = fig[ sq_b_height ][ 0 ] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height ][ sq_b_width ] = CORNER_SYMB;
}

// Function definition of makeSquare()
void makeSquare ( char fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] )
{
	int
		i, j,                         // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		str_end     = FIG_AREA_WIDTH - 1; // The end of the drawing area (including borders) 

	for ( i = 1; i < sq_b_height; ++i )
	{
		for ( j = 1; j < sq_b_width; ++j )
		{
			// Drawing the square
			fig[ i ][ j ] = SQ_SYMB;

			// Horizontal border assingments
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Vertical border assingments
		fig[ i ][ 0 ]           = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ]  = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width] = fig[sq_b_height][0] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height][sq_b_width] = CORNER_SYMB;
}

// Function definition of makeRectangle()
void makeRectangle (char fig[FIG_AREA_HEIGHT][FIG_AREA_WIDTH])
{
	int
		i, j, k,                      // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		rec_width   = sq_b_width - 7, // Rectangle's width
		str_end     = FIG_AREA_WIDTH - 1; // The end of the drawing area (including borders) 

	for ( i = 1; i < sq_b_height; ++i )
	{
		// Horizontal border assingments
		for ( j = 1; j < sq_b_width; ++j )
		{
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Drawing the rectangle
		for ( k = 7; k < rec_width; ++k )
		{
			fig[ i ][ k ] = REC_SYMB;
		}

		// Vertical border assingments
		fig[ i ][ 0 ]           = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ]  = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width ] = fig[ sq_b_height ][ 0 ] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height ][ sq_b_width ] = CORNER_SYMB;
}

// Function definition of makeTriangle()
void makeTriangle ( char fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] )
{
	int
		i, j, k, l,                   // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		str_end     = FIG_AREA_WIDTH - 1, // The end of the drawing area ( including borders )
		vertex = ( int ) floor( sq_b_width / 2 ); // Triangle's vertex horizontal position

	for ( i = 1, k = vertex; i < sq_b_height; ++i, --k )
	{
		for ( j = 1; j < sq_b_width ; ++j )
		{
			// Drawing the triangle
			for ( l = k; l <= sq_b_width - k; ++l )
			{
				fig[ i ][ l ] = TR_SYMB;
			}

			// Horizontal border assingments
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Vertical border assingments
		fig[ i ][ 0 ]          = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ] = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width ] = fig[ sq_b_height ][ 0 ] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height ][ sq_b_width ] = CORNER_SYMB;
}

// Function definition of makeCircle()
void makeCircle  ( char fig[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] )
{
	int
		i, j,                         // Loop counters
		sq_b_height = FIG_AREA_HEIGHT - 1,     // The end of the maximum figure's height
		sq_b_width  = FIG_AREA_WIDTH - 2, // The end of the maximum figure's width
		str_end     = FIG_AREA_WIDTH - 1; // The end of the drawing area ( including borders );
	char
		crcl[ FIG_AREA_HEIGHT ][ FIG_AREA_WIDTH ] =
		{
			"+                      + ",
			"       **********        ",
			"    ****************     ",
			"  ********************   ",
			" **********************  ",
			" **********************  ",
			" **********************  ",
			" **********************  ",
			"  ********************   ",
			"    ****************     ",
			"       **********        ",
			"+                      + "
		}; // Default circle prototype

	for ( i = 1; i < sq_b_height; ++i )
	{
		for ( j = 1; j < sq_b_width; ++j )
		{
			// Changing default filling symbol to "FILL_SYMB" constant
			if ( crcl[ i ][ j ] == ' ' )
			{
				crcl[ i ][ j ] = FILL_SYMB;
			}

			// Changing default circle drawing symbol to "CIRCLE_SYMB" constant
			if ( crcl[ i ][ j ] == '*' )
			{
				crcl[ i ][ j ] = CIRCLE_SYMB;
			}

			fig[ i ][ j ] = crcl[ i ][ j ];

			// Horizontal border assingments
			fig[ 0 ][ j ]           = TOP_B_SYMB; // Top border
			fig[ sq_b_height ][ j ] = BOT_B_SYMB; // Bottom border
		}

		// Vertical border assingments
		fig[ i ][ 0 ]           = L_B_SYMB; // Left border
		fig[ i ][ sq_b_width ]  = R_B_SYMB; // Right border

		// String end assingment
		fig[ i ][ str_end ] = '\0';
	}

	fig[ 0 ][ str_end ] = fig[ sq_b_height ][ str_end ]  = '\0'; // First and last line ends'
	                                                             // assingments respectively

	// Corner symbol assingments
	fig[ 0 ][ sq_b_width ] = fig[ sq_b_height ][ 0 ] =
	fig[ 0 ][ 0 ] = fig[ sq_b_height ][ sq_b_width ] = CORNER_SYMB;
}
