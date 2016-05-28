class Solution 
{
public:
    int maxArea( vector<int>& height ) 
    {
        int maxValue = 0;
        int leftIndex = 0;
        int rightIndex =  height.size() - 1;
        while ( leftIndex < rightIndex )
        {
            const int leftValue = height[leftIndex];
            const int rightValue = height[rightIndex];
            const int value = ( rightIndex - leftIndex ) * min( leftValue, rightValue );
            if ( value > maxValue ) maxValue = value;
            if ( leftValue < rightValue ) while ( height[++leftIndex] <= leftValue );
            else while ( height[--rightIndex] <= rightValue );
        }
        return maxValue;
    }
};
