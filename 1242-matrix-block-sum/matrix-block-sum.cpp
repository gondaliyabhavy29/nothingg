class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

    const int h = mat.size(), w = mat[0].size();
    
    vector< vector<int> > integralImg = vector< vector<int> >(h, vector< int >(w, 0) );
    vector< vector<int> > outputImg = vector< vector<int> >(h, vector< int >(w, 0) );
    
    
    
    for( int y = 0 ; y < h ; y++){
        int pixelSum = 0;
        
        for( int x = 0 ; x < w ;x++){
            pixelSum += mat[y][x];
            integralImg[y][x] = pixelSum;
            
            if( y > 0 ){ 
                integralImg[y][x] += integralImg[y-1][x];
            }
        }
    }
    
    
   
    for( int y = 0 ; y < h ; y++){
        
        const int minRow = max(0, y-k), maxRow = min(h-1, y+k);
        
        for( int x = 0 ; x < w ;x++){
            
            const int minCol = max(0, x-k), maxCol = min(w-1, x+k);
            
            outputImg[y][x] = integralImg[maxRow][maxCol];
            
            if( minRow > 0 ){
                outputImg[y][x] -= integralImg[minRow-1][maxCol];
            }
            
            if( minCol > 0 ){
                outputImg[y][x] -= integralImg[maxRow][minCol-1];
            }
            
            if( (minRow > 0) && (minCol > 0) ){
                outputImg[y][x] += integralImg[minRow-1][minCol-1];
            }
        }
    }
        
    return outputImg;        
    }
};