// Library inclusions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// ANSI colour definitions
enum COLOURS
{
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
};

// Constant definitions
#define ESC 0x1B // Escape sequence

#define LIST_AREA_WIDTH 37 // Horizontal border of the menu area (amount of symbols)
#define FIG_AREA_WIDTH  25 // Horizontal border of the drawing area (amount of symbols, should
						   // be equal to FIG_AREA_HEIGHT * 2 + 1)
#define FIG_AREA_HEIGHT 12 // FIG_AREA_HEIGHT of the "list" and the "fig" area

#define RES_DELAY 3 // Defines how much time the result will be shown (seconds)

#define RECTANGLE '1' // Rectangle's ID
#define SQUARE    '2' // Square's ID
#define TRIANGLE  '3' // Triangle's ID
#define CIRCLE    '4' // Circle's ID
#define HLINE     '5' // Horizontal line's ID
#define XLINES    '6' // Intersecting lines' ID

#define REC_SYMB    '*'	// Square drawing symbol
#define SQ_SYMB     '*' // Square drawing symbol
#define TR_SYMB     '*' // Triangle drawing symbol
#define CIRCLE_SYMB '*' // Circle drawing symbol
#define HLINE_SYMB  '*' // Horizontal line drawing symbol
#define XLINES_SYMB '*'	// Intersecting lines rawing symbol

#define TOP_B_SYMB  ' ' // Top border symbol of the figure drawing area
#define BOT_B_SYMB  ' '	// Bottom border symbol of the figure drawing area
#define L_B_SYMB    ' ' // Left border symbol of the figure drawing area
#define R_B_SYMB    ' ' // Right border symbol of the figure drawing area
#define CORNER_SYMB '+' // Corner symbol of the figure drawing area
#define FILL_SYMB   ' ' // Defines empty space symbol of drawing area

#define INTRO_AREA_COLOUR  MAGENTA // Text colour of the intro area
#define LIST_AREA_COLOUR   GREEN   // Text colour of the list area
#define FIGURE_AREA_COLOUR CYAN    // Text colour of the figure drawing area
#define BOTTOM_AREA_COLOUR YELLOW  // Text colour of the bottom area (request / timer)

#define REQUEST_INPUT_AREA_COLOUR WHITE // Text colour of the request input data
#define TIMER_OUTPUT_AREA_COLOUR  WHITE // Text colour of the timer output data
						   						   
// Function prototypes
void draw (const unsigned short, char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH], int time_left);

void makeRectangle (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]);
void makeSquare	   (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]); 
void makeTriangle  (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]); 
void makeCircle	   (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]); 
void makeHLine	   (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]); 
void makeXLines	   (char [FIG_AREA_HEIGHT][FIG_AREA_WIDTH]); 

void setColour (unsigned short);
void _clear    (void);
