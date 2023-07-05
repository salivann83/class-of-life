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


int main(){
  for(int i = 0 ; i <= 20 ; i++){
    cout << "enter number" << endl ; 
  cout <<"1_genome" << endl << "2_cell" << endl << "3_animal" << endl ;
  int w ;
  cin >> w ;
    if(w==1){
      genome g ;
      g.get_gen() ;
      cout << "what do you want to do ?" << endl << "1_make dna" << endl <<"2_small jahesh" << endl << "3_big jahesh" << endl<< "4_reverse jahesh"<<endl ;
      int d ;
      cin >> d ;
      if(d==1){
        string rna ;
          cout << "enter rna" ;
          cin >> rna ;
          g.make_dna(rna);
      }
      else if (d==2){
        char a , b ;
               int n ;
               cin >> a >> b >> n ;
               g.small_jahesh_DNA(a,b,n);
             
      }
      else if (d == 3){
        string s1 , s2 ;
            cin >> s1 , s2;
            g.big_jahesh_DNA(s1,s2);
          
      }
      else if(d== 4){
        string s3 ;
            cin >> s3 ;
            g.reverse_jahesh_DNA(s3);
      }
    }
      
    else if (w == 2){
      cell c ;
      c.get_gen_chro();
      cout << "what do you want to do ?"<< endl << "1_big rejahesh" << endl << "2_small rejahesh" << endl << "3_reverse jahesh" << endl << "4_palindrome" << endl ;
      int d2 ;
      cin >> d2 ;
      if(d2==1){
        string a , b ;
          int m , n ;
          cin >> a >> b >> m >> n ;
          c.big_rejahesh(a,m,b,n);
      }
      else if (d2 == 2){
        char a , b ;
               int n,m ;
               cin >> a >> b >> n >> m ;
             c.small_rejahesh(a,b,n,m);
      }
      else if (d2 == 3 ){
        string a ;
            int n ;
            cin >> a >> n ;
            c.rereverse(a,n);
      }
      else if (d2 == 4){
        c.pal_mok();
      }
    }
      
                 
      
    else if (w==3){
      cout << "what do you want to do ?" << endl << "1_darsad tashaboh"<< endl << "2_gune yabi " << "3_tolid mesl qeyr jensi" << endl << "4_tolid mesle jensi" << endl ;
       int d3 ;
       cin >> d3 ;
       animal a1 ;
       if(d3==1){
           cell c1 ;
           cell c2 ;
           c1.get_gen_chro();
           c2.get_gen_chro() ;
           cout << a1.Tashaboh_Persentage(c1,c2);
       }
           
         else if (d3 == 2){
           cell c11;
           cell c12 ;
           c11.get_gen_chro();
           c12.get_gen_chro() ;
            cout << a1.Tashkhise_Gune(c11,c12);
      } 
             
        else if (d3 == 3){
          cell c3 ;
        c3.get_gen_chro();
        animal a(c3);
           a1.No_Sexual(a);
          
      }
        
      else if (d3==4){
          cell c4;
          cell c5 ;
        c4.get_gen_chro() ;
        c5.get_gen_chro() ;
        animal b(c4) ;
        animal c(c5);
        a1.Sexual(b,c);     
       }
    }
         
  }
  
}
