# Time-Travelling File System

A Git-like in-memory version control system built in C++ 
using custom Tree, HashMap and Heap data structures.

## Compile

```bash
bash compile.sh
```

## Run

```bash
./output
```

## Commands

CREATE filename
READ filename
INSERT filename "content"
UPDATE filename "content"
SNAPSHOT filename "message"
ROLLBACK filename [versionID]
HISTORY filename
RECENT_FILES num
BIGGEST_TREES num

## Example

CREATE notes.txt
INSERT notes.txt "hello world"
SNAPSHOT notes.txt "first save"
INSERT notes.txt "new line"
HISTORY notes.txt
ROLLBACK notes.txt 1
READ notes.txt

## Implementation

- Each file maintains a tree of versions for maintaining version history of each file.
- HashMap for O(1) version lookup by their unique ID
- Max Heap for tracking recent/biggest files
- All three data structures implemented from scratch

## Edge Cases

- Duplicate file creation is rejected
- Rollback on root node prints error
- Invalid version ID on rollback prints error
- Snapshot on already snapshotted version prints error
- READ on empty file prints "File is empty"
