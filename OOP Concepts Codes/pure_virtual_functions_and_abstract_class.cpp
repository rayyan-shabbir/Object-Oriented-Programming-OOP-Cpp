#include <iostream>
using namespace std;

//Abstract Class
class CWH {
	protected:
		string title;
		float ratings;
	public:

		CWH(string t, float r) {
			this->title = t;
			this->ratings = r;
		}
		virtual void display() = 0;
};

//Concrete Class
class CWHVideo : public CWH
{
	float vLength;
	public:
		CWHVideo(string t, float r, float vL) : CWH(t, r) 
		{
			this->vLength = vL;
		}
		void display() {
			cout << "This video has a title " << title << endl;
			cout << "Ratings: " << ratings << " Out of 5." << endl;
			cout << "Length of this video is: " << vLength << endl;
		}
};

//Concrete Class
class CWHText : public CWH
{
	int words;
	public:
		CWHText(string t, float r, int wc) : CWH(t, r)
		{
			words = wc;
		}
		void display() {
			cout << "This video has a title " << title << endl;
			cout << "Ratings: " << ratings << " Out of 5." << endl;
			cout << "Count of words is: " << words << endl;
		}
};

int main() {
    // CWH obj1;   --->  ERROR ... Because object of Abstract Class cannot be created

	string title = " ";
	float ratings = 0;

	//For CODE WITH HARRY Video
	title = "Django tutorial";
	ratings = 4.89;
	float vLength = 3.37;

	CWHVideo djVideo(title, ratings, vLength);
	//djVideo.display();

	//For CODE WITH HARRY Text
	title = "Django tutorial";
	ratings = 4.89;
	float words = 521;

	CWHText djText(title, ratings, words);
	//djText.display();

    // CWH obj1;   --->  ERROR ... Because object of Abstract Class cannot be created.

	CWH *tuts[2];  // --->  Valid ... Because pointer of Abstract Class can be created.

	tuts[0] = &djVideo;
	tuts[1] = &djText;

	tuts[0]->display();
	cout << endl;
	tuts[1]->display();
	return 0;
}