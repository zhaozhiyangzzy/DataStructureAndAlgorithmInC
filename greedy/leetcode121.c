int maxProfit(int* prices, int pricesSize){
  int min = 0;
  int i = 0;
  int max = 0;
  //init min
  for(i=0;i<pricesSize;i++){
      if(prices[i] > min){
        min = prices[i];
      }
  }
  for(i=0;i<pricesSize;i++){
    if(prices[i] <= min){
      min = prices [i];
    }
    else{
      if((prices[i]-min)>max){
        max = prices[i]-min;
      }
    }
  }
  return max;
}
