#include <bits/stdc++.h>
using namespace std;
template <class ItemType>
struct item{
	ItemType value;
	item* next_ptr;
	item* pre_ptr;
};

template <class ItemType>
class Bag{
	private:
		item<ItemType>* head_ptr;//dummy element
		item<ItemType>* tail_ptr;
		item<ItemType>* ptr;//now point to
		item<ItemType>* garbage;//erased node
		int NowItemNum;
		int totalNum;//total Num in Bag
		bool needInitial;
		ItemType nothing;
	public:
		Bag():head_ptr(NULL),tail_ptr(NULL),ptr(NULL),NowItemNum(0),totalNum(0),needInitial(true){
			nothing=ItemType();			
			cout<<"Bag constructed"<<endl;
		}

		~Bag(){
			deleteAllNode();
			cout<<"Bag destructed"<<endl;
		}

		Bag(const Bag<ItemType> & my_Bag):head_ptr(NULL),tail_ptr(NULL),ptr(NULL),NowItemNum(0),totalNum(0),needInitial(true){			
			nothing=ItemType();			
			copyAllNode(my_Bag);
			cout<<"Bag copy constructed"<<endl;
		}

		Bag<ItemType>& operator=(const Bag<ItemType> & my_Bag){	
			if(totalNum!=0) deleteAllNode();
			copyAllNode(my_Bag);	
			cout<<"Bag assignment operator"<<endl;	
			return (*this);
		}

		bool empty() const{
			if(totalNum==0) return true;
			return false;
		}

		int uniqueSize() const{
			int i,j,counter=0;
			item<ItemType>* p=head_ptr;
			ItemType arr[totalNum];
			for(i=1;i<=totalNum;i++){
				for(j=0;j<totalNum;j++){	
					if(arr[j]==p->value) break;
				}
				if(j==totalNum) arr[counter++]=p->value;
				p=p->next_ptr;
			}
			return counter;
		}

		bool insert(const ItemType &value){	
			needInitial=true;		
			item<ItemType>* tempptr=tail_ptr;
			if(tail_ptr!=NULL){
				tail_ptr=tempptr->next_ptr;
			}
			//set item value
			tail_ptr=new item<ItemType>;
			//cout<<"insert tail_ptr:"<<tail_ptr<<endl;
			//cout<<"insert value:"<<value<<endl;	
			tail_ptr->value=value;
			tail_ptr->next_ptr=NULL;
			tail_ptr->pre_ptr=tempptr;
			//connect
			if(tempptr!=NULL) tempptr->next_ptr=tail_ptr;
			//cout<<"insert:"<<tail_ptr<<" pre:"<<tempptr<<endl;
			tail_ptr->next_ptr=head_ptr;
			totalNum++;
			//if this one is first one, make head_ptr point to it
			if(head_ptr==NULL){
				head_ptr=tail_ptr;
			}
		}

		int find(const ItemType& value){ //find same value pos, and set ptr=pos
			int i;	
			ptr=head_ptr;	
			for(i=1;i<=totalNum;i++){
				//cout<<"find ptr:"<<ptr<<endl;
				if(ptr->value==value) break;
				ptr=ptr->next_ptr;
			}
			if(i>totalNum) return 0;//not found; 
			return i;//return find pos index
		}

		bool contains(const ItemType &value){
			item<ItemType>* p=ptr;
			if(find(value)==0) {ptr=p;return false;}
			ptr=p;//find will move ptr, so we need to set it back	
			return true;
		}

		int count(const ItemType& value) const{
			int i,sum=0;	
			item<ItemType>* p=head_ptr;	
			for(i=1;i<=totalNum;i++){
				//cout<<"v:"<<p->value<<endl;
				if(p->value==value) sum++;
				p=p->next_ptr;
			}
			return sum;
		}

		int erase(const ItemType& value){
			needInitial=true;				
			int num=find(value);	
			if(num==0){
				//cout<<"can't find this item to erase"<<endl;
				return 0;
			}
			item<ItemType>* pre=ptr->pre_ptr;
			item<ItemType>* next=ptr->next_ptr;
			if(head_ptr==ptr) head_ptr=next;	
			delete ptr;ptr=NULL;
			if(pre!=NULL) pre->next_ptr=next;
			if(next!=NULL) next->pre_ptr=pre;
			totalNum--;
			return num;
		}

		int eraseAll(const ItemType& value){
			needInitial=true;
			int num=count(value);
			int counter=0;
			while(contains(value)){
				erase(value);
				counter++;
			}
			//if delete num!= num,delete have error	
			if(counter!=num) cout<<"eraseAll error"<<endl;
			return num;			
		}

		void start(){
			if(empty()) cout<<"Please input item"<<endl;
			else{
				ptr=head_ptr;
				needInitial=false;
				NowItemNum=1;
			}
		}

		void next(){
			if(needInitial) cout<<"Please initializes"<<endl;	
			else if(ended()){
				ptr=NULL;
				needInitial=true;
			}
			else{
				ptr=ptr->next_ptr;
				NowItemNum+=1;
			}
		}

		bool ended() const{
			if(NowItemNum==totalNum) return true;
			return false;
		}

		const ItemType& currentValue() const{
			if(needInitial){
				cout<<"Please initializes"<<endl;	
				return nothing;
			}
			else return ptr->value;
		}

		int currentCount() const{
			if(needInitial){
				cout<<"Please initializes"<<endl;
				return 0;	
			}		
			return NowItemNum;
		}

		int size() const{
			return totalNum;
		}

		item<ItemType>* getFirstItem() const{
			return head_ptr;
		}

		void deleteAllNode(){
			int i;	
			item<ItemType> *p1,*p2;
			p1=head_ptr;
			//cout<<"total:"<<totalNum<<endl;
			for(i=1;i<=totalNum;i++){
				//cout<<"deleteAllNode p:"<<p1<<endl;
				p2=p1->next_ptr;
				delete p1;p1=NULL;
				p1=p2;	
			}
			head_ptr=NULL;
			tail_ptr=NULL;
			needInitial=true;
			totalNum=0;
			
		}

		void copyAllNode(const Bag<ItemType> & my_Bag){
			int i;	
			item<ItemType> *p=my_Bag.getFirstItem();
			//cout<<"copyAllNode first item:"<<p<<endl;
			for(i=1;i<=my_Bag.totalNum;i++){
				insert(p->value);
				p=p->next_ptr;
			}
			//cout<<"head:"<<head_ptr<<endl;
		}

		void printAllItem() const{ //print all item in result
			int i;	
			item<ItemType> *ptr=head_ptr;	
			for(i=1;i<=totalNum;i++){
				cout<<"("<<i<<")"<<ptr->value<<endl;
				ptr=ptr->next_ptr;
			}

		}
		void copyValueArr(ItemType* arr) const{
			int i;
			item<ItemType> *ptr=head_ptr;	
			for(i=0;i<size();i++){
				arr[i]=ptr->value;
				ptr=ptr->next_ptr;			
			}
		}
		void pasteValueArr(ItemType* arr,int size){
			int i;
			//cout<<"size="<<size<<endl;
			for(i=0;i<size;i++){
				insert(arr[i]);
			}
		}

};
template <class ItemType>
void combine(const Bag<ItemType>& bag1,const Bag<ItemType>& bag2, Bag<ItemType>& result){
	//special case
	//if(&bag1==&bag2||&bag2==&result||&bag1==&result){	
		int arrsize=bag1.size()+bag2.size();
		//cout<<"arrsize:"<<arrsize<<endl;
		ItemType arr[arrsize];
		bag1.copyValueArr(&arr[0]);
		bag2.copyValueArr(&arr[bag1.size()]);
		result.deleteAllNode();
		result.pasteValueArr(arr,arrsize);
	/*}else{
		result=bag1;
		result.copyAllNode(bag2);
	}*/
}

template <class ItemType>
void subtract(const Bag<ItemType>& bag1,const Bag<ItemType>& bag2, Bag<ItemType>& result){
	int i;
	//special case
	//if(&bag1==&bag2||&bag2==&result||&bag1==&result){	
		int arr1size=bag1.size();	
		int arr2size=bag2.size();		
		ItemType arr1[arr1size];
		ItemType arr2[arr2size];
		bag1.copyValueArr(&arr1[0]);
		bag2.copyValueArr(&arr2[0]);
		result.deleteAllNode();
		result.pasteValueArr(arr1,arr1size);
		for(i=0;i<arr2size;i++){
			//cout<<arr2[i]<<endl;
			if(result.contains(arr2[i])){ 
				//cout<<"*"<<endl;				
				result.erase(arr2[i]);}	
		}
	/*}else{
		result=bag1;
		item<ItemType> *p=bag2.getFirstItem();
		for(i=1;i<=bag2.size();i++){
			if(result.contains(p->value)) result.erase(p->value);	
			p=p->next_ptr;
		}	
	}*/

}

