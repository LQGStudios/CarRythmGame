#include "raylib.h"
#include "libs/raymath.h"
#include <list>
#include <fstream> //för att läsa csv med beatmaps
 
struct Song 
{   
    Music music;

};
struct CurrentSong //Värdena i denna struct ska ändras medans man spelar 
{
    private:

    public:
        double songPosition; //time
        int notesHit;
        int notesMissed;
        
    
};
struct Beatmap
{
    public:
        int lane;
        int measure;
        int beat;
        float beatPosition; //relativ till songPosition
        void LoadBeatMap(const char*bPath) //läser in en csv-fil med beatmappen i. Denna beatmap kommer från ett excel-dokument med timing och annan notinformation
        {
            std::ifstream fullBeatmap;
            fullBeatmap.open(bPath);

            if (fullBeatmap.fail())
            {
                std::cerr << "Kan inte öppna filen" << bPath <<std::endl; //skickar ett smidigt errormeddelande
            }
            
            int i; //för denna while-loop
            
            while (fullBeatmap.peek() != EOF) //medans vi läser filen, innan den har tagit slut alltså, kollar vi på tabellen rad för rad
            {
            //read line of beatmap
                std::string lmb; //något av de 3 värdena i csv-filen(l står för värdet i kolumn 0, vilken fil på vägen (0-4) m i kolumn 1, vilken takt, b i kolumn 2, alltså vilket taktslag noten ska dyka upp på)
                getline(fullBeatmap, lmb, ',');
                std::cout << lmb <<std::endl;
                
                switch (i)
                {
                case 0: //l
                    //talet är i första kolumnen, ska då behandlas som taktslag
                    //spawna not i lane nr lmb
                    
                    //Note(lmb);
                    std::cout << "reading lane";
                    lane = stoi(lmb);

                    break;
                case 1:
                    std::cout << "reading measure";
                    measure = stoi(lmb);
                    break;
                case 2: //m 
                    std::cout << "reading beat";
                    beat = stoi(lmb);

                    i= -1;//så att i ska bli 0 igen
                    break;
                default:
                    i=-1; //så att i ska bli 0 igen
                    break;
                }
                
                //Note(lane);

                i++;
            }
            fullBeatmap.close();

        }
};
typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

void StartTimer(Timer* timer, double lifetime)
{
    std::cout << "startade timer";
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}