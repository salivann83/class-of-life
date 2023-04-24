#include "cell.h"
#include <iostream>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std ;
class animal{
	private:

		cell c ;
	
	public :
		
		 animal (cell a ){
			c= a ;
		}
		
		animal(){
		}
		
	     double Tashaboh_Persentage	(cell a , cell b){
	     	int check = a.GetDna().size() - b.GetDna().size() ;
	     	int moshabeh ;
	     	double persentage ;
	     	if (check >= 0 ) {
	     		for (int k = 0 ; k < b.GetDna().size() ; k ++){
	     			if (a.GetDna()[k] == b.GetDna()[k]){
	     				moshabeh +=1 ;
					}
				}
				persentage = (moshabeh *100.0) / a.GetDna().size() ;
			}
			else {
				for (int k = 0 ; k < a.GetDna().size() ; k ++){
	     			if (a.GetDna()[k] == b.GetDna()[k]){
	     				moshabeh +=1 ;
					}
				}
				persentage = (moshabeh *100.0) / b.GetDna().size() ;
			}
			return persentage ;
		}
		
		bool Tashkhise_Gune (cell a , cell b){
			if(a.GetDna().size() == b.GetDna().size()  &&  Tashaboh_Persentage(a , b )>= 70){
				return true ;
			}
			else {
				return false ;
			}
		}
		
		
		bool operator == (animal a){
			animal b ;
			if(a.c.GetDna().size() == b.c.GetDna().size() && Tashaboh_Persentage(a.c, b.c) >= 70 ){
				return true ;
			}
			else{
				return false ;
			} 
			
		}
         
         

        void No_Sexual (animal a ){
            vector <string> Bache = a.c.GetDna() ;
            int first = 7 ;
            int random = 7 + (rand() %4) ;
            int change = 10 - random ;
            char ch[4] = {'A' , 'T' , 'C' , 'G'} ;
            for(int i = change ; i >0 ; i--){
            	Bache.pop_back() ;
			}
            for(int i = 0 ; i < change ; i++){
                string s3 = "";
                for(int j = 0 ; j < 20 ; j++){
                    s3+= ch[rand() %4] ;
                }
                Bache.push_back(s3) ;
                

            }
            for ( int j = 0 ; j < Bache.size() ; j++){
            	cout << Bache[j] << endl ;
			}


        }
        
        void Sexual (animal a , animal b){
        	if (Tashkhise_Gune(a.c , b.c)){
        		if(a.c.GetDna().size() % 2 == 0){
        			vector <string> Bache ;
        			int random1 = rand() %a.c.GetDna().size() ;
        			int random2 = rand() %a.c.GetDna().size() ;
        			for(int i = 0 ; i< a.c.GetDna().size() /2 ; i++){
        				if(random1 >= a.c.GetDna().size()){
        					random1 -= a.c.GetDna().size();
						}
						if(random2 >= a.c.GetDna().size()){
        					random2 -= a.c.GetDna().size();
						}
						Bache.push_back(a.c.GetDna()[random1]) ;
						Bache.push_back(b.c.GetDna()[random2]) ;
						random1 ++ ;
						random2 ++ ;
					}
					for(int i = 0 ; i< Bache.size() ; i++){
				        cout << Bache[i] << endl ;
			        }
				}
				
			}
			
		}
		
		
		void operator+ (animal a){
			animal b ;
			if (Tashkhise_Gune(a.c , b.c)){
        		if(a.c.GetDna().size() % 2 == 0){
        			vector <string> Bache ;
        			int random1 = rand() %a.c.GetDna().size() ;
        			int random2 = rand() %a.c.GetDna().size() ;
        			for(int i = 0 ; i< a.c.GetDna().size() /2 ; i++){
        				if(random1 >= a.c.GetDna().size()){
        					random1 -= a.c.GetDna().size();
						}
						if(random2 >= a.c.GetDna().size()){
        					random2 -= a.c.GetDna().size();
						}
						Bache.push_back(a.c.GetDna()[random1]) ;
						Bache.push_back(b.c.GetDna()[random2]) ;
						random1 ++ ;
						random2 ++ ;
					}
					for(int i = 0 ; i< Bache.size() ; i++){
				        cout << Bache[i] << endl ;
			        }
				}
				
			}
			
		}		
};

