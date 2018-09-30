class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        //////////////////////////////////////////////////
        // 1. find max value from row
        // 2. find max value from column
        // 3. the min of both max value is the height
        //////////////////////////////////////////////////
        
        int initial_total_height = 0;
        int increased_total_height = 0;
        int row_count = grid.size();
        int column_count = grid[0].size();
        vector<int> max_row_value(row_count);
        
        // Collect initial total height
        for (int a=0; a<row_count; a++)
        {
            for (int b=0; b<column_count; b++)
            {
                initial_total_height += grid[a][b];
            }
        }
        
        // 1. find max value from row
        for (int a=0; a<row_count; a++)
        {
            int max_value_from_row = 0;
            for (int b=0; b<column_count; b++)
            {
                if (grid[a][b] > max_value_from_row)
                {
                    max_value_from_row = grid[a][b];
                }
            }
            max_row_value[a] = max_value_from_row;
            //cout << "max_row[" << a << "] = " << max_row_value[a] << endl;
        }
        
        // 2. find max value from column
        for (int a=0; a<column_count; a++)
        {
            int max_value_from_column = 0;
            for (int b=0; b<row_count; b++)
            {
                if (grid[b][a] > max_value_from_column)
                {
                    max_value_from_column = grid[b][a];
                }
            }
            //cout << "max_column[" << a << "] = " << max_value_from_column << endl;
            
            // 3. the min of both max value is the height
            for (int b=0; b<row_count; b++)
            {
                grid[b][a] = min(max_value_from_column, max_row_value[b]);
            }
        }
        
        // Collect output
        for (int a=0; a<row_count; a++)
        {
            for (int b=0; b<column_count; b++)
            {
                increased_total_height += grid[a][b];
            }
        }
        
        return increased_total_height - initial_total_height;
    }
};
