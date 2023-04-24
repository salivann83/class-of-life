#include<iostream>
#include<map>
#include<cstdlib>
#include<vector>
#include<string>
#include <algorithm> 
#pragma <once>
using namespace std;


class cell;
class genome
{
    private:
    string RNA;
    string DNA_p1;
    string DNA_p2;
    string DNA_RNA;
    friend class cell;


    public:
    map<char, char> mokamel;
    vector<int> count;
    vector<int> count2;
    
    
    genome()
    {
        mokamel.insert(pair<char , char > ('A','T'));
        mokamel.insert(pair<char , char > ('T','A'));
        mokamel.insert(pair<char , char > ('C','G'));
        mokamel.insert(pair<char , char > ('G','C'));
    }
    void get_gen()//daryaft mohtavaye gene
    {
        cout<<"ENTER RNA : ";
        cin>>RNA;
        cout<<"ENTER DNA FIRST PART : ";
        cin>>DNA_p1;
        cout<<"ENTER DNA SECOND PART : ";
        cin>>DNA_p2;

    }
    void make_dna(string rna)//sakht dna az rna
    {
        for (int i = 0 ; i<rna.length() ; i++)
        {
            if (rna[i] == 'A')
            {
                cout<<mokamel['A'];
            } 
            else if (rna[i] == 'T' )
            {
                cout<<mokamel['T'];
            }
            else if (rna[i] == 'G' )
            {
                cout<<mokamel['G'];
            }
            else if (rna[i] == 'C' )
            {
                cout<<mokamel['C'];
            }

        }
    }
    void small_jahesh_DNA(char a ,char b ,int c)//jahesh koochak dna
    {
        int test = 0;
        for (int i = 0 ; i<DNA_p1.length() ; i++)
        {

            if (DNA_p1[i] == a)
            {
                test++;
                DNA_p1[i] = b;


            }     
            if (test == c)
            {
                break;
            }
            if(DNA_p2[i] == a)
            {
                test ++;
                DNA_p2[i] = b;
            }
        
            if (test == c)
            {
                break;
            }
        }
    }
    void small_jahesh_RNA(char a ,char b ,int c)//jahesh koochak rna
    {
        count.clear();
        for (int i = 0 ; i<RNA.length();i++)
        {
            if(RNA[i] == a )
            {
                count.push_back(i);
            }
            
        }
    
        if(count.size() >= c)//age to reshte aval bood
        {
            for(int j = 0 ; j<c ; j++)
            {
                RNA[count[j]] = b;
            }
        }
    }
    void big_jahesh_RNA(string a , string b)//jaheshe bozorg rna
    {
        for( int i = 0 ; i< RNA.length() ; i++)
        {
            if ( RNA[i] == a[0])
            {
                if(RNA.substr(i , a.length()) == a)
                {
                    
                    RNA.erase(i,a.length());
                    RNA.insert(i,b);
                
                }
            }
        

        }
    }
    void big_jahesh_DNA(string a , string b)//jahesh bozorg Dna
    {
        int begin_p1 = 0;
        int begin_p2 = 0;
        begin_p1 = DNA_p1.find(a);
        begin_p2 = DNA_p2.find(a);
        if(begin_p1>begin_p2 && begin_p2 != -1)
        {
            DNA_p2.erase(begin_p2,a.length());

            DNA_p2.insert(begin_p2,b);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_b);
        }
        else if(begin_p1>begin_p2 && begin_p2 == -1)
        {
            DNA_p1.erase(begin_p1,a.length());

            DNA_p1.insert(begin_p1,b);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_b);
        }
        else if(begin_p1<begin_p2 && begin_p1 != -1)
        {
            DNA_p1.erase(begin_p1,a.length());

            DNA_p1.insert(begin_p1,b);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_b);
        }
        else if(begin_p1<begin_p2 && begin_p1 == -1)
        {
            DNA_p2.erase(begin_p2,a.length());

            DNA_p2.insert(begin_p2,b);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_b);
        }
    
        else if (begin_p1==begin_p2)
        {
            DNA_p2.erase(begin_p2,a.length());

            DNA_p2.insert(begin_p2,b);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_b = b;
            for(int k = 0 ; k<b.length() ; k++)
            {
                mokamel_b[k] = mokamel[b[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_b);
        }
    
    }

    void reverse_jahesh_RNA(string a)//jaheshe makoos
    {
        for( int i = 0 ; i< RNA.length() ; i++)
        {
            if ( RNA[i] == a[0])
            {
                if(RNA.substr(i , a.length()) == a)
                {
                    
                    RNA.erase(i,a.length());
                    reverse(a.begin(), a.end()); 
                    RNA.insert(i,a);
                
                }
            }
        
    }
    
}
    void reverse_jahesh_DNA(string a)
    {
        int begin_p1 = -1;
        int begin_p2 = -1;
        for( int i = 0 ; i< DNA_p1.length() ; i++)
        {
            if ( DNA_p1[i] == a[0])
            {
                if(DNA_p1.substr(i , a.length()) == a)
                {
                    begin_p1 = i;
                }
            }
        }
        for( int i = 0 ; i< DNA_p2.length() ; i++)
        {
            if ( DNA_p2[i] == a[0])
            {
                if(DNA_p2.substr(i , a.length()) == a)
                    {
                    for (int j = 0 ; j < a.length(); j++)
                    {
                        begin_p2 = i;
                    } 
                }
            }
        }
        if(begin_p1>begin_p2 && begin_p2 != -1)
        {
            DNA_p2.erase(begin_p2,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p2.insert(begin_p2,a);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_a);
        }
    
        else if(begin_p1 > begin_p2 && begin_p2 == -1)
        {
            DNA_p1.erase(begin_p1,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p1.insert(begin_p1,a);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_a);
        }
    
        else if(begin_p1 < begin_p2 && begin_p1 == -1)
        {
            DNA_p2.erase(begin_p2,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p2.insert(begin_p2,a);
            DNA_p1.erase(begin_p2,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p1.insert(begin_p2,mokamel_a);
        }
    
        else if(begin_p1 < begin_p2 && begin_p1 != -1)
        {
            DNA_p1.erase(begin_p1,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p1.insert(begin_p1,a);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_a);
        }
    
        else if(begin_p1 == begin_p2)
        {
             DNA_p1.erase(begin_p1,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p1.insert(begin_p1,a);
            DNA_p2.erase(begin_p1,a.length());
            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p2.insert(begin_p2,mokamel_a);
        }
    
    
    }
    







};


class cell
{
    private:
    int n_chro;
    vector<string>DNA_p1_chro;
    vector<string>DNA_p2_chro;
    friend class genome;
    
    
    
    public:
    
    map<char, char> mokamel;
    cell()
    {
        mokamel.insert(pair<char , char > ('A','T'));
        mokamel.insert(pair<char , char > ('T','A'));
        mokamel.insert(pair<char , char > ('C','G'));
        mokamel.insert(pair<char , char > ('G','C'));
    }
    
    vector <string> GetDna(){
    	return DNA_p1_chro ;
	}
    
    void get_gen_chro()
    {
        string DNA_p1;
        string DNA_p2;

        cout<<"ENTER  NUMBER OF chromosome: ";
        cin>>n_chro;
        for (int i = 0 ; i<n_chro ; i++)
        {
            cout<<"DNA of of "<<i+1<<"chromosome";
            cout<<"ENTER DNA_p1 OF CHRO"<<endl;
            cin>>DNA_p1;
            DNA_p1_chro.push_back(DNA_p1);
            cout<<"ENTER DNA_p2 OF CHRO";
            cin>>DNA_p2;
            DNA_p2_chro.push_back(DNA_p2);
        } 
    }


    void death_of_cell()
    {
         
        
        string dnap1;
        string dnap2;
        int n_of_d =0 ;
        for(int j = 0 ; j<n_chro ; j++)
        {
            dnap1 = DNA_p1_chro[j];
            dnap2 = DNA_p2_chro[j];

        
            for(int i = 0 ; i<dnap1.length() ; i++)
            {
                if(mokamel[dnap1[i]]== dnap2[i])
                {
                    n_of_d++;

                }     
            }
        

            if(n_of_d>=5)
            {
                DNA_p1_chro.erase(DNA_p1_chro.begin()+j);
                DNA_p2_chro.erase(DNA_p2_chro.begin()+j);
                n_chro = n_chro+1;
            }
        
        }
        
    }

    void big_rejahesh(string a,int m,string b,int n)
    {
        cout<< "ENTER S1, NUMBER OF CHRO1, S2, NUMBER OF CHRO2"<< endl;
        cin>> a; 
        cin>> m;
        cout<< "s1: " << a<< "in chrom number: " << m<< endl;
        cin>> b;
        cin>> n;
        cout<< "s2: " << b<< "in chrom number: " << n<< endl;
        int begin_p1_chro ;
        int begin_p2_chro ;
        int begin_p1_chro_n;
        int begin_p2_chro_n;
        begin_p1_chro_n = DNA_p1_chro[n].find(b);
        begin_p2_chro_n = DNA_p2_chro[n].find(b);
        
        begin_p1_chro = DNA_p1_chro[m].find(a);
        begin_p2_chro = DNA_p2_chro[m].find(a);
        if(begin_p1_chro >= begin_p2_chro && begin_p2_chro !=-1 )
        {
            DNA_p2_chro[m].erase(begin_p2_chro,a.length());

            DNA_p2_chro[m].insert(begin_p2_chro,b);
        }
    
        else if( begin_p1_chro < begin_p2_chro && begin_p1_chro !=-1 )
        {
            DNA_p1_chro[m].erase(begin_p1_chro,a.length());

            DNA_p1_chro[m].insert(begin_p1_chro,b);
        }
        else if(begin_p1_chro < begin_p2_chro && begin_p1_chro ==-1)
        {
            DNA_p2_chro[m].erase(begin_p2_chro,a.length());

            DNA_p2_chro[m].insert(begin_p2_chro,b);
        }
        
        else if(begin_p1_chro > begin_p2_chro && begin_p2_chro ==-1 )
        {
            DNA_p1_chro[m].erase(begin_p1_chro,a.length());

            DNA_p1_chro[m].insert(begin_p1_chro,b);
        }
        
        if(begin_p1_chro_n > begin_p2_chro_n && begin_p1_chro_n !=-1 )
        {
            DNA_p2_chro[n].erase(begin_p2_chro,b.length());

            DNA_p2_chro[n].insert(begin_p2_chro,a);
        }
    
        else if(begin_p1_chro_n < begin_p2_chro_n && begin_p1_chro_n ==-1 )
        {
            DNA_p2_chro[n].erase(begin_p2_chro,b.length());

            DNA_p2_chro[n].insert(begin_p2_chro,a);
        }
        else if(begin_p1_chro_n < begin_p2_chro_n && begin_p2_chro_n !=-1)
        {
            DNA_p1_chro[n].erase(begin_p1_chro,b.length());

            DNA_p1_chro[n].insert(begin_p1_chro,a);
        }
        else if(begin_p1_chro_n > begin_p2_chro_n && begin_p2_chro_n ==-1)
        {
            DNA_p1_chro[n].erase(begin_p1_chro,b.length());

            DNA_p1_chro[n].insert(begin_p1_chro,a);
        }

        else if (begin_p1_chro_n ==  begin_p2_chro_n )
        {
            DNA_p1_chro[n].erase(begin_p1_chro,b.length());

            DNA_p1_chro[n].insert(begin_p1_chro,a);
        }

        else if(begin_p1_chro ==  begin_p2_chro)
        {
            DNA_p1_chro[m].erase(begin_p1_chro,a.length());

            DNA_p1_chro[m].insert(begin_p1_chro,b);
        }
    }

    void small_rejahesh(char a ,char b ,int n , int m )
    {
        int test = 0;
        for (int i = 0 ; i<DNA_p1_chro[m].length() ; i++)
        {

            if (DNA_p1_chro[m][i] == a)
            {
                test++;
                DNA_p1_chro[m][i] = b;
                DNA_p2_chro[m][i] = mokamel[b];    

            }     
            if (test == n)
            {
                break;
            }
            if(DNA_p2_chro[m][i] == a)
            {
                test ++;
                DNA_p2_chro[m][i] = b;
                DNA_p1_chro[m][i] = mokamel[b];
            }
        
            if (test == n)
            {
                break;
            }
        }
    }

    void rereverse(string a , int n)
    {
        int begin_p1_chro = 0;
        int begin_p2_chro = 0;
        for( int i = 0 ; i< DNA_p1_chro[n].length() ; i++)
        {
            if ( DNA_p1_chro[n][i] == a[0])
            {
                if(DNA_p1_chro[n].substr(i , a.length()) == a)
                {
                    begin_p1_chro = i;
                }
            }
        }
        for( int i = 0 ; i< DNA_p2_chro[n].length() ; i++)
        {
            if ( DNA_p2_chro[n][i] == a[0])
            {
                if(DNA_p2_chro[n].substr(i , a.length()) == a)
                    {
                    for (int j = 0 ; j < a.length(); j++)
                    {
                        begin_p2_chro = i;
                    } 
                }
            }
        }
        if(begin_p1_chro>begin_p2_chro)
        {
            DNA_p2_chro[n].erase(begin_p2_chro,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p2_chro[n].insert(begin_p2_chro,a);
            DNA_p1_chro[n].erase(begin_p2_chro,a.length());

            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]];

            }
            DNA_p1_chro[n].insert(begin_p2_chro,mokamel_a);
        }
    
        else
        {
            DNA_p1_chro[n].erase(begin_p1_chro,a.length());
            reverse(a.begin(), a.end()); 
            DNA_p1_chro[n].insert(begin_p1_chro,a);
            DNA_p2_chro[n].erase(begin_p1_chro,a.length());

            string mokamel_a = a;
            for(int k = 0 ; k<a.length() ; k++)
            {
                mokamel_a[k] = mokamel[a[k]] ;

            }
            DNA_p2_chro[n].insert(begin_p2_chro,mokamel_a);
        }
    
    }

    void pal_mok()
    {   
        string rev_d;
        string pal;
        string mok_d;
        string a;
        for(int j = 0 ; j<n_chro ; j++)
        {
            for(int i = 0 ; i<DNA_p1_chro[j].length();i++)
            {
                a = DNA_p1_chro[j];
                for(int k = 3 ; k<a.length() ; k++)
                {
                    pal = a.substr(i , k);
                    mok_d = a.substr(i , k);
                    for (int d = 0 ; d<mok_d.length() ; d++)
                    {
                        mok_d[d] = mokamel[mok_d[d]];
                    }    
                    reverse(mok_d.begin(), mok_d.end());
                    if(mok_d == pal)
                    {
                        cout<<"pal: "<<pal<<endl;
                    }
                        
                } 
            } 
        }
    
        for(int j = 0 ; j<n_chro ; j++)
        {
            for(int i = 0 ; i<DNA_p2_chro[j].length();i++)
            {
                a = DNA_p2_chro[j];
                for(int k = 3 ; k<a.length() ; k++)
                {
                    pal = a.substr(i , k);
                    mok_d = a.substr(i , k);
                    for (int d = 0 ; d<mok_d.length() ; d++)
                    {
                        mok_d[d] = mokamel[mok_d[d]];
                    }    
                    reverse(mok_d.begin(), mok_d.end());
                    if(mok_d == pal)
                    {
                        cout<<"pal: "<<pal<<endl;
                    }
                        
                } 
            } 
        }
    
    
    }
};






