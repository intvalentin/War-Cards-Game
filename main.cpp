#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <cstdlib>  
#include <algorithm> 

using namespace std;

int random(int i){ 
			return rand()%i;
		}

class Joc{
	private:
		struct PachetCarti{
    	char tip,carte;
    	int id;
		};
		
		
		
		list<struct PachetCarti> pachet;
		list<struct PachetCarti> Playera;
		list<struct PachetCarti> Playerb;
	
		int jucatori;
		
	public:
			joc();
		void ImparteCartile();
		void SeJoaca();
		void Pachetc();
		
};


int main() {
	
	Joc Razboi;
    
    
    Razboi.Pachetc();
    
    
    cout<<"----------------------------------"<<endl;
    cout<<"[Apasati ENTER sa inceapa jocul] "; cin.ignore();
    
    
    Razboi.ImparteCartile();
	Razboi.SeJoaca();
}

void Joc::Pachetc(){
	PachetCarti el;
	char tip[] = {'I','R','T','N'};
    char carte[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    int id[]= {2,3,4,5,6,7,8,9,10,12,13,14,11};
    for (int j=0; j<13; j++) {
        for (int i=0; i<4; i++) {
        	
        	el.tip=tip[i];
        	el.carte=carte[j];
        	el.id=id[j];
            pachet.push_back(el);
        }               
    }
 //Se amesteca pachetul de carti.
	srand ( unsigned ( time(0) ) );
    vector<struct PachetCarti> Temp(pachet.size());
    copy(pachet.begin(),pachet.end(),Temp.begin());
    random_shuffle ( Temp.begin(), Temp.end(),random);
    copy(Temp.begin(),Temp.end(),pachet.begin());
    
 /*
    list<PachetCarti>::iterator it;
   	it= pachet.begin();
   	for(it;it!=pachet.end();it++)
    cout<<"Carte: "<<it->carte<<" Tip: "<<it->tip<<endl;
  */	
   
}

void Joc::ImparteCartile(){
	
	list<PachetCarti>::iterator it;
	PachetCarti el;
	
	for(it=pachet.begin(); it !=pachet.end();++it){
		
			el.tip=(it)->tip; el.carte=(it)->carte; el.id=(it)->id;
			Playera.push_back(el);
			++it;
			el.tip=(it)->tip; el.carte=(it)->carte; el.id=(it)->id;
			Playerb.push_back(el);
		}
		
	
	pachet.clear();
  //Vezi ce carti au primit.
    cout<<"Playera carti:"<<endl;	
	it=Playera.begin();
	for(it; it!=Playera.end();it++)
    cout<<"Carte: "<<it->carte<<" Tip: "<<it->tip<<endl;
    
    cout<<"------------------"<<endl;
    cout<<"Playerb carti:"<<endl;
	it=Playerb.begin();
	for(it; it!=Playerb.end();it++)
    cout<<"Carte: "<<it->carte<<" Tip: "<<it->tip<<endl;
    
    cout<<"------------------"<<endl;

}

void Joc::SeJoaca(){
	int temp=jucatori,aux=3;
	
	list<PachetCarti>::reverse_iterator playera=Playera.rbegin();
	list<PachetCarti>::reverse_iterator playerb=Playerb.rbegin();
	list<PachetCarti>::reverse_iterator auxa;
	PachetCarti el;
	

			
			while( (playera!=Playera.rend()) && (playerb!=Playerb.rend())){
				
				if( (playera)->id > (playerb)->id){
					cout<<"---------------"<<endl;
					cout<<"IF A>B: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
					
					
					el.tip=(playerb)->tip; el.carte=(playerb)->carte; el.id=(playerb)->id;
					Playera.push_front(el);
					el.tip=(playera)->tip; el.carte=(playera)->carte; el.id=(playera)->id;
					Playera.push_front(el);
					Playera.pop_back();
					Playerb.pop_back();
						
						playera=Playera.rbegin();
						playerb=Playerb.rbegin();
					
						
						
				}
				if((playera)->id < (playerb)->id){
					cout<<"---------------"<<endl;
					cout<<"IF A<B: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
					
					el.tip=(playera)->tip; el.carte=(playera)->carte; el.id=(playera)->id;
					Playerb.push_front(el);
					el.tip=(playerb)->tip; el.carte=(playerb)->carte; el.id=(playerb)->id;
					Playerb.push_front(el);
					Playerb.pop_back();
					Playera.pop_back();
						
						playera=Playera.rbegin();
						playerb=Playerb.rbegin();
						
						
				}
				
		RAZBOI:	if((playera)->id == (playerb)->id){
						cout<<"-----------"<<endl;
						cout<<"IF FIRST a = b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
						playera++; playera++;
						playerb++; playerb++; 
						
						if((playera)->id == (playerb)->id){
							
							cout<<"IF SECOND a = b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
							aux=aux+2;
							goto RAZBOI;
						}
						
						if( (playera)->id > (playerb)->id){
								cout<<"-----------"<<endl;
								//cout<<"IF a > b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
								
								while(aux > 0 && (Playerb.rend()!=playerb)){
									
									playerb=Playerb.rbegin();
									playera=Playera.rbegin();
									cout<<"IF a > b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
									el.tip=(playerb)->tip; el.carte=(playerb)->carte; el.id=(playerb)->id;
									Playera.push_front(el);
									el.tip=(playera)->tip; el.carte=(playera)->carte; el.id=(playera)->id;
									Playera.push_front(el);
									
									Playerb.pop_back();
									Playera.pop_back();
									
									aux--;
								}
								cout<<"IF A>B EXIT: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
							aux=3;
							
						}
					
						else if((playera)->id < (playerb)->id){
							cout<<"-----------"<<endl;
							//cout<<"IF a < b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
							
								while(aux > 0 && (Playera.rend()!=playera)){
									
									playerb=Playerb.rbegin();
									playera=Playera.rbegin();
									cout<<"IF a < b RAZBOI: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
									el.tip=(playera)->tip; el.carte=(playera)->carte; el.id=(playera)->id;
									Playerb.push_front(el);
									el.tip=(playerb)->tip; el.carte=(playerb)->carte; el.id=(playerb)->id;
									Playerb.push_front(el);
									Playerb.pop_back();
									Playera.pop_back();
									
									aux--;
									
								}
								cout<<"IF A<B EXIT: "<<(playera)->carte<<" "<<(playerb)->carte<<endl;
								aux=3;
						}
						
					}
					
					
			}
			
			if(playerb==Playerb.rend()){
				cout<<"PlayerA este castigator!";
				temp=0;
			}
			else{
				cout<<"PlayerB este castigator!";
				temp=0;
			}
		
		
	
	
}

