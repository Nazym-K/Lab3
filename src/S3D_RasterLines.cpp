
void S3D_DrawLineX(S3D_Renderer* renderer, int row, int x0, int x1, Color color)
{
	if (x0 > x1) std::swap(x0, x1);

	S3D_Rectangle bounds;
	bounds.min.x = x0;
	bounds.max.x = x1;
	bounds.min.y = row;
	bounds.max.y = row;
	assert(S3D_CheckScreenContainsRec(renderer, bounds));

	// for x in x0 to x1:
	//		set pixel at x, row
	for (int x = x0;x<x1; x++)
	{
		S3D_SetPixelColor(renderer->color_buffer, x, row, color);
	}
}

void S3D_DrawLineY(S3D_Renderer* renderer, int col, int y0, int y1, Color color)
{
	if (y0 > y1) std::swap(y0, y1);

	S3D_Rectangle bounds;
	bounds.min.y = y0;
	bounds.max.y = y1;
	bounds.min.x = col;
	bounds.max.x = col;
	assert(S3D_CheckScreenContainsRec(renderer, bounds));

	// for y in y0 to y1:
	//		set pixel at col, y

	for (int y = y0; y < y1; y++)
	{
		S3D_SetPixelColor(renderer->color_buffer, col, y, color);
	}
}

void S3D_DrawLine(S3D_Renderer* renderer, int x0, int y0, int x1, int y1, Color color0, Color color1 = BLANK)
{


	int dx = x1 - x0;
	int dy = y1 - y0;


	S3D_Rectangle bounds;
	bounds.min.x = x0 < x1 ? x0 : x1;
	bounds.min.y = y0 < y1 ? y0 : y1;
	bounds.max.x = bounds.min.x + abs(dx);
	bounds.max.y = bounds.min.y + abs(dy);
	assert(S3D_CheckScreenContainsRec(renderer, bounds));

	// let steps = abs dx if abs dx > abs dy, else abs dy
	float steps = 0.0f;
	if (abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	// abs = "absolute value"

	// let x_step = dx / steps as float
	float x_step = dx / steps;
	// let y_step = dy / steps as float
	float y_step = dy / steps;
	float x = x0;
	float y = y0;
	S3D_SetPixelColor(renderer->color_buffer, x, y, color0);
	// set pixel at x, y
	// for i in steps:
	//		x += x_step
	//		y += y_step
	//		set pixel at x, y
	for (int i = 0; i <= steps; i++)
	{
		x += x_step;
		y += y_step;

		S3D_SetPixelColor(renderer->color_buffer, x, y, color0);
	}
}
