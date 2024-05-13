# binary-file-operation
## Simple C++ binary file operation like load & save file, copy, split and merge files.
## Guide:
### With Command-line argument based application, you need to change directory first:
* ### Ex: cd C:\binary-file-operation\x64\Debug\

### 1. MYCOPYFILE
* ### Ex: MYCOPYFILE -s D:/film.mkv -d D:/Level1/Level2/Level3

### 3. MYSPLITFILE
* ### Ex: MYSPLITFILE -s D:/film.mkv -d D:/Level1/Level2/Level3 -numpart 3
* ### Ex: MYSPLITFILE -s D:/film.mkv -d D:/Level1/Level2/Level3 -sizeapart 1000000

### 5. MYMERGEFILE
* ### Ex: MYMERGEFILE -s D:/Level1/Level2/Level3/film.mkv.part01 -d D:/NewLevel
