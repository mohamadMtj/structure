#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

class songNode{
public: 
	int songID;
	string songName;
	string singerName;
	string songGenre;
	string songTime;
	
	songNode* left;
	songNode* right; 


	songNode(int ID,string Name, string singer, string time, string genre) { 
		this->songID = ID;
		this->songName = Name;
		this->singerName = singer;
		this->songTime = time;
		this->songGenre = genre;
		this->left = nullptr;
		this->right = nullptr;
	}
};
class D_Link_List {
private:
	songNode* first;
    songNode* end;

public:	 
	D_Link_List() {
		first = nullptr;
		end = nullptr;
	}

	void displayPlaylist() {
		songNode* p = first;
		while (p) {
			cout << "Name: " << p->songName << ", Singer: " << p->singerName << ", Genre: " << p->songGenre << ", Duration: " << p->songTime << " minutes" << endl;
			p = p->right;
		}
	}

	void addSong(int ID, string Name, string singer, string time, string genre) {
		songNode* newNode = new songNode(ID,Name, singer, time, genre);
		if (!first) {
			first = newNode;
			end = newNode;
		}
		else { 
			end->right = newNode;
			newNode->left = end;
			end = newNode; 
		}
	}

	int deleteSong(string songName) {
		songNode* p = first;
		while (p) {
			if (p->songName == songName) {
				if (p->left) {
					p->left->right = p->right;
				}
				else {
					first = p->right;
				} if (p->right) {
					p->right->left = p->left;
				}
				else {
					end = p->left;
				}
				delete p;
				cout << songName << " has been deleted from the playlist.\n";
				return 1;
			}
			p = p->right;
		}
		cout << songName << " is not found in the playlist.\n";
		return 0;

	}

	void deleteSongsBySinger(string singer) { 
		songNode* p = first;
		while (p) {
			if (p->singerName == singer) {
				songNode* x = p;
				if (p->left) {
					p->left->right = p->right;
				} 
				else {
					first = p->right;
				} 
				if (p->right) {
					p->right->left = p->left;
				} 
				else {
					end = p->left; 
				} 
				p = p->right;
				delete x; 
			} 
			else {
				 p = p->right;
			}
		} 
	}


	void deleteSongsByGenre(string genre) {
		songNode* p = first;
		while (p) {
			if (p->songGenre == genre) {
				songNode* x = p;
				if (p->left) {
					p->left->right = p->right;
				}
				else {
					first = p->right;
				}
				if (p->right) {
					p->right->left = p->left;
				}
				else {
					end = p->left;
				}
				p = p->right;
				delete x;
			}
			else {
				p = p->right;
			}
		}
	}
	
	void searchSong(string attribute, string value) {
		songNode* p = first;
		bool found = false;

		while (p) {
			if ((attribute == "name" && p->songName == value) ||
			(attribute == "singer" && p->singerName == value) ||
				(attribute == "genre" && p->songGenre == value)) {
					cout << "Found: " << p->songName << " by " << p->singerName << ", Genre: " << p->songGenre << ", Duration: " << p->songTime << " minutes" << endl;
					found = true;
					break;
				}
				p = p->right; 
			}
				if (!found) {
					cout << "The song you're searching for was not found.\n";
			}

	}

	//void swap(songNode*& a, songNode*& b) {
	//	if (a == b) return;

	//	if (a->right == b) {
	//		// Nodes are adjacent
	//		a->right = b->right;
	//		if (b->right) b->right->left = a;
	//		b->left = a->left;
	//		if (a->left) a->left->right = b;
	//		b->right = a;
	//		a->left = b;
	//	}
	//	else if (b->right == a) {
	//		// Nodes are adjacent and swapped
	//		b->right = a->right;
	//		if (a->right) a->right->left = b;
	//		a->left = b->left;
	//		if (b->left) b->left->right = a;
	//		a->right = b;
	//		b->left = a;
	//	}
	//	else {
	//		// Nodes are non-adjacent
	//		songNode* aLeft = a->left;
	//		songNode* aRight = a->right;
	//		songNode* bLeft = b->left;
	//		songNode* bRight = b->right;

	//		if (aLeft) aLeft->right = b;
	//		if (aRight) aRight->left = b;
	//		if (bLeft) bLeft->right = a;
	//		if (bRight) bRight->left = a;

	//		a->left = bLeft;
	//		a->right = bRight;
	//		b->left = aLeft;
	//		b->right = aRight;
	//	}

	//	if (!a->left) first = a;
	//	if (!b->left) first = b;
	//	if (!a->right) end = a;
	//	if (!b->right) end = b;
	//}





	void swap(songNode* a, songNode* b) {
		string tempSongName = a->songName;
		string tempSingerName = a->singerName;
		string tempTime = a->songTime;
		string tempGenre = a->songGenre;
		a->songName = b->songName;
		a->singerName = b->singerName;
		a->songTime = b->songTime;
		a->songGenre = b->songGenre;
		b->songName = tempSongName;
		b->singerName = tempSingerName;
		b->songTime = tempTime;
		b->songGenre = tempGenre;
	}

	void sortSongsByName() { 
		if (!first || !first->right) return;

		bool swapped; 

		do {
			swapped = false; 
			songNode* q = first; 

			while (q->right) { 
				if (q->songName > q->right->songName) { 
					swap(q, q->right);
					swapped = true;
				}
				q = q->right; 
			}
		} while (swapped); 
	}

	void sortSongsBySinger() { 
		if (!first || !first->right) return; 

		bool swapped; 

		do {
			swapped = false; 
			songNode* q = first; 

			while (q->right) { 

				
				if (q->singerName > q->right->singerName) { 
					
					swap(q, q->right); 
					swapped = true; 
				}

				q = q->right;
			}
		} while (swapped); 
	}
	 
	void moveSongUp(string songName) {
		songNode* p = first;
		while (p) {
			if (p->songName == songName && p->left) {
				songNode* leftNode = p->left;
				swap(p, leftNode); 
				break;
			}
			p = p->right;
		} 
	}

	void moveSongDown(string songName) { 
		songNode* p = first;
		while (p) {
			if (p->songName == songName && p->right) {
				songNode* rightNode = p->right;
				swap(p, rightNode);
				break;
			} 
			p = p->right;
		}
	} 

	 void shuffleSongs() {
			 if (!first) return;

			 vector<int> songIDs;
			 songNode* p = first;

			 while (p) {
				 songIDs.push_back(p->songID);
				 p = p->right;
			 }

			  
			 if (!songIDs.empty()) {
				 int randomIndex = rand() % songIDs.size(); 
				 int selectedID = songIDs[randomIndex];
				 cout << "Playing song with ID: " << selectedID << endl;
				 p = first;
				 while (p) {
					 if (p->songID == selectedID) {
						 cout << "Playing: " << p->songName << " by " << p->singerName << ", Genre: " << p->songGenre << ", Time: " << p->songTime << endl;
						 break;
					 }
					 p = p->right;
				 }
			 }	 
	 } 

	  void DeleteRepetitive() {
	    	if (!first) return;
			songNode* p = first;
			while (p) {
				songNode* q = p->right;
				while (q) {
					if (p->songName == q->songName) {
						songNode* repetitive = q;
						if (q->left) { 
							q->left->right = q->right;
						}
						if (q->right) {
							q->right->left = q->left;
						} 
						q = q->right;
						delete q;
					}
					else {
						q = q->right;
					}
				}
				p = p->right; 
			}
		} 
};

int main() {
	
	D_Link_List playlist;
	int choice, songID;
	
	/*playlist.addSong(1,"yadegary", "mahyar", "1:30", "Rock");
	playlist.addSong(2,"nakhla", "hidden", "0:30", "Jazz");
	playlist.addSong(3,"avaz", "ahmadvand", "1:45", "Hip-Hop");
	playlist.addSong(4,"ghasedak", "vinak", "2:12", "rap");
	playlist.addSong(5,"beynemon", "pobon", "3:05", "pop");*/

	string songName, singer,time, genre, attribute,value;
	while (true) {
		cout << "Menu:\n";
		cout << "1. Add Song\n";
		cout << "2. Delete Song\n";
		cout << "3. Delete Songs by Singer\n";
	    cout << "4. Delete Songs by Genre\n";
		cout << "5. Display Playlist\n";
		cout << "6. Sort Songs by Name\n"; 
		cout << "7. Sort Songs by Singer\n";
		cout << "8. Search Song\n";
		cout << "9. Move Song Up\n";
		cout << "10. Move Song Down\n";
		cout << "11. Shuffle Songs\n";
		cout << "12. Remove Duplicates\n";
		cout << "13. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter Song ID: ";
			cin >> songID;
			cout << "Enter Song Name: ";
			cin >> songName;
			cout << "Enter Singer Name: ";
			cin >> singer;
			cout << "Enter Song Genre: ";
			cin >> genre;
			cout << "Enter Song Duration (minutes : second): ";
			cin >> time;
			playlist.addSong(songID,songName, singer,  time, genre);
			break;
		case 2:
			cout << "Enter Song Name to delete: ";
			cin >> songName;
			playlist.deleteSong(songName);
			break;
		case 3:
			cout << "Enter Singer Name to delete all their songs: ";
			cin >> singer;
			playlist.deleteSongsBySinger(singer);
			break;
		case 4:
			cout << "Enter Genre to delete all songs of that genre: ";
			cin >> genre;
			playlist.deleteSongsByGenre(genre);
		case 5:
			playlist.displayPlaylist();
			break;
		case 6:
			playlist.sortSongsByName();
			cout << "Playlist sorted by song names." << endl;
			playlist.displayPlaylist();
			break;
		case 7:
			playlist.sortSongsBySinger();
			cout << "Playlist sorted by singer names." << endl;
			playlist.displayPlaylist();
			break;
		case 8: 
			cout << "Enter search attribute (name/singer/genre): "; 
			cin >> attribute; 
			cout << "Enter value to search for: "; 
			cin >> value;
			playlist.searchSong(attribute, value);
			break;
		case 9:
		cout << "Enter Song Name to move up: ";
		cin >> songName;
		playlist.moveSongUp(songName);
		break;
		case 10:
			cout << "Enter Song Name to move down: ";
			cin >> songName;
			playlist.moveSongDown(songName);
			break;
		case 11:
			playlist.shuffleSongs(); 
			break;
		case 12: 
			playlist.DeleteRepetitive();
			cout << "Repetitive songs have been removed." << endl;
			break;
		case 13:
			exit(0);
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	}
	return 0;
}


	