# 🎵 Music Playlist Manager 🎧

> A badass C++ console playlist manager powered by **Doubly Linked List**  
> 💻 University project – *Data Structures Course*

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| ➕ Add Song | Insert new song with ID, name, singer, genre, duration |
| ❌ Delete Song | Remove a song by name |
| 🎤 Delete by Singer | Remove all songs of a specific artist |
| 🎸 Delete by Genre | Nuke an entire genre from the playlist |
| 📋 Display Playlist | Show all songs in order |
| 🔍 Search Song | Find song by name / singer / genre |
| 📊 Sort by Name | Alphabetical order by song name |
| 🎙️ Sort by Singer | Alphabetical order by singer name |
| ⬆️ Move Up | Shift a song upward in the list |
| ⬇️ Move Down | Shift a song downward |
| 🎲 Shuffle | Play a random song from the playlist |
| 🧹 Remove Duplicates | Delete repetitive songs (by name) |
| 🚪 Exit | Close the program |

---

## 🧠 Data Structure

```
🎵 Node (song) ←→ 🎵 Node (song) ←→ 🎵 Node (song)
     ↑                   ↑                   ↑
   left                left                left
   right               right               right
```

**Doubly Linked List** – each node connects to both previous and next song.  
✅ Efficient move up/down  
✅ Easy deletion from anywhere  
✅ Bidirectional traversal  

---

## 🛠️ Compile & Run

### Requirements
- C++11 or higher
- g++ / clang++ / MSVC

### Terminal Commands

```bash
g++ playlist.cpp -o playlist
./playlist
```

### Or just use Code::Blocks / VS Code / CLion 🤷

---

## 🎮 Menu Preview

```
Menu:
1. Add Song
2. Delete Song
3. Delete Songs by Singer
4. Delete Songs by Genre
5. Display Playlist
6. Sort Songs by Name
7. Sort Songs by Singer
8. Search Song
9. Move Song Up
10. Move Song Down
11. Shuffle Songs
12. Remove Duplicates
13. Exit
Enter your choice: _
```

---

## 📸 Example Run

```
Enter Song ID: 101
Enter Song Name: Yadegary
Enter Singer Name: Mahyar
Enter Song Genre: Rock
Enter Song Duration: 3:45
✅ Song added!

Displaying Playlist:
🎵 Yadegary - Mahyar [Rock] 🕒 3:45
```

---

## 🐛 Known Issues

- Sorting swaps song data but keeps old ID (IDs may mismatch)
- No file save/load (playlist lost after exit)

---

## 🚀 Future Upgrades (Maybe 🤔)

- 💾 Save/Load playlist to/from file
- 🔄 Merge Sort instead of Bubble Sort (faster!)
- 🎨 Add colors to console output
- 📱 GUI version with Qt

---

## 👨‍💻 Author

**Your Name**  
Data Structures Course – Fall/Spring 2025  
📌 GitHub: [your-username]

---

## 📜 License

📚 Educational use only – feel free to fork and learn!
