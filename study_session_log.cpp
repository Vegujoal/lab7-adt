/*
 * Course: COEN 2220 - Programming 2
 * Name: [Jose Alejandro Vera Guagua]
 * Lab: Lab 7 - Abstract Data Types
 * Description: ADT contract, implementation, and client code practice
 * Due date: [Tuesday, October 1, 2026]
 */

#include <iostream>
using namespace std;

/*
 * StudySessionLog ADT
 *
 * Data:
 * TODO (Part C): Describe the study session durations managed by this ADT.
 *Almacena la duracion de las sesiones de estudio en minutos, hasta una capacidad fija de cuatro sesiones.

 * Operations:
 * TODO (Part C): Describe addSession(minutes), including its result when the log cannot accept another session.
 * Agrega una nueva duracion de sesion de estudio en minutos. Devuelve true si la sesion se agrego correctamente.
 * False si el registro esta lleno y no puede aceptar mas sesiones.

 * TODO (Part C): Describe totalMinutes().
 *Devuelve el total de minutos de todas las sesiones de estudio almacenadas.

 * TODO (Part C): Describe longestSession() and its precondition.
 * Devuelve la duracion de la sesion de estudio mas larga almacenada.
 * La precondicion es que el registro no debe estar vacio cuando se llama a esta funcion.
 
 * TODO (Part C): Describe size() and isEmpty().
 * Devuelve el numero de sesiones de estudio almacenadas y reporta si el registro esta vacio.
 */

	class StudySessionLog
	{
	private:
		// ===== Resolve these TODOs later (Part D) =====

		// TODO (Part D): Add a fixed capacity constant of four study sessions.
		static const int MAX_SESSIONS = 4;

		// TODO (Part D): Add an int array named sessionMinutes for the stored session durations.
		int sessionMinutes[MAX_SESSIONS];

		// TODO (Part D): Add an int that tracks how many study sessions are stored.
		int numSessions;

	public:
		// TODO (Part D): Write a constructor that creates an empty log.
		StudySessionLog(){
			numSessions = 0;
		}

		// TODO (Part D): Write addSession. It receives minutes and reports whether the session was stored.
		bool addSession(int minutes){
			if (numSessions >= MAX_SESSIONS) {
				return false; 
			}
			sessionMinutes[numSessions] = minutes; 
			numSessions++; 
			return true; 
		}

		// TODO (Part D): Write totalMinutes as a const member function.
		int totalMinutes() const{
			int total = 0;
			for (int i = 0; i < numSessions; ++i) {
				total += sessionMinutes[i]; 
			}
			return total; 
		}

		// TODO (Part D): Write longestSession as a const member function.
		int longestSession() const{
			int longest = sessionMinutes[0]; 
			for (int i = 1; i < numSessions; ++i) {
				if (sessionMinutes[i] > longest) {
					longest = sessionMinutes[i]; 
				}
			}
			return longest; 
		}

		// TODO (Part D): Write size as a const member function.
		int size() const{
			return numSessions;
		}

		// TODO (Part D): Write isEmpty as a const member function.
		bool isEmpty() const{
			return numSessions == 0;
		}
	};

int main()
{
    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudySessionLog object and print whether it starts empty.
    StudySessionLog log;
    cout << boolalpha << "Log starts empty: " << log.isEmpty() << endl;
	cout << endl;
    // TODO (Part E): Add four dummy session durations and attempt to add a fifth.
    int logDurations[] = {20, 45, 63, 89};
    for (int i = 0; i < 4; ++i)
    {
        log.addSession(logDurations[i]);
    }

    // TODO (Part E): Print the number of stored sessions and whether the fifth session was accepted.
    cout << "Number of stored sessions: " << log.size() << endl;
	cout <<  endl;
    bool fifthSessionAdded = log.addSession(120);
    cout << boolalpha << "Fifth session added: " << fifthSessionAdded << endl;
	cout << endl;
    // TODO (Part E): Print the total minutes and the longest stored session.
    cout << "Total minutes: " << log.totalMinutes() << endl;
	cout << endl;
    cout << "Longest session: " << log.longestSession() << endl;
	cout << endl;
    // TODO (Part E): Print descriptive English labels for all results.

    return 0;
}