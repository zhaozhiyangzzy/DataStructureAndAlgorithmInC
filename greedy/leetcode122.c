int maxProfit(int* prices, int pricesSize){
  int first = 0;
  int second = 0;
  int total = 0;
  while((first<pricesSize)&&(second<pricesSize)){
    if(first == second){
      second++;
    }
    else{
      if(prices[first]<prices[second]){
        total = total + (prices[second] - prices[first]);
        first = second;
      }
      else{
        first = second;
      }
    }
  }
return total;
}
