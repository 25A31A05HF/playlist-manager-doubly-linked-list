#include <iostream>
#include <limits>
using namespace std;

// Node structure
struct Song {
    string title;
    Song* next;
    Song* prev;
};

// Global pointers
Song* head = NULL;
Song* tail = NULL;
Song* current = NULL;

// Add song
void addSong(string name) {
    Song* newSong = new Song();
    newSong->title = name;
    newSong->next = NULL;
    newSong->prev = NULL;
    if (head == NULL) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    cout << "Song added: " << name << endl;
}

// Display playlist
void display() {
    Song* temp = head;
    if (temp == NULL) {
        cout << "Playlist is empty\n";
        return;
    }
    cout << "Playlist:\n";
    while (temp != NULL) {
        if (temp == current)
            cout << " >> " << temp->title << " (current)" << endl;
        else
            cout << "    " << temp->title << endl;
        temp = temp->next;
    }
}

// Play current song
void playCurrent() {
    if (current != NULL)
        cout << "Now playing: " << current->title << endl;
    else
        cout << "Playlist is empty\n";
}

// Next song
void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        playCurrent();
    } else {
        cout << "No next song\n";
    }
}

// Previous song
void prevSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        playCurrent();
    } else {
        cout << "No previous song\n";
    }
}

// Delete song
void deleteSong(string name) {
    Song* temp = head;
    while (temp != NULL) {
        if (temp->title == name) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) head->prev = NULL;
            } else if (temp == tail) {
                tail = temp->prev;
                if (tail != NULL) tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            if (current == temp) {
                current = (temp->next != NULL) ? temp->next : temp->prev;
            }

            delete temp;
            cout << "Song deleted\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Song not found\n";
}

// Main function
int main() {
    string line;
    int choice;
    string name;

    while (true) {
        cout << "\n1. Add\n2. Display\n3. Play\n4. Next\n5. Previous\n6. Delete\n7. Exit\n";
        cout << "Choose an option: ";

        getline(cin, line);
        choice = 0;
        if (!line.empty()) {
            choice = line[0] - '0';
        }

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                addSong(name);
                break;
            case 2:
                display();
                break;
            case 3:
                playCurrent();
                break;
            case 4:
                nextSong();
                break;
            case 5:
                prevSong();
                break;
            case 6:
                cout << "Enter song to delete: ";
                getline(cin, name);
                deleteSong(name);
                break;
            case 7:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
