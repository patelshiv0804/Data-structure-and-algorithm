class slidding {
    public static void main(String[] args) {
        
    }

    public int maxSatisfied ( int[] customer , int[] grumpy , int minutes){
        int i = 0 ;
        int windowsum = 0 ;
        int length = customer.length ;
        int maxsum = Integer.MIN_VALUE ;
        int index = -1 ;
        for ( i = 0 ; i < minutes ; i++){
            windowsum += customer[i];
        }

        for( i = minutes ; i < length ; i++){
           
             
           windowsum = windowsum - customer[ i - minutes] + customer[i] ;
 
           if ( windowsum > maxsum){
              maxsum = windowsum ; 
              index = i ;
           }  
        }

        int j = 0 ;
        for ( j = 0 ; j< length ; j++){

            if ( index < j < index + minutes){
               customer[j] = customer[j];
            }
            else {
               if (grumpy[j] != 0){
                 customer[j] = 0 ;
               }   
            }
        }
        
        int sum = 0;
        for ( i = 0 ; i < length ; i++){
            sum += customer[i];
        }
        return sum ;

    }

}