struct ListNode;
typedef struct ListNode * Position;
struct HashTbl;
typedef struct HashTbl * HashTable;
typedef int Element;

HashTable InitializeTable(int TableSize);
void destroyTable(HashTable H);
Position Find(ElementTYpe Key,HashTable H);
void Insert(ElementType Key,HashTable H);
ElementType Retrieve(Position P);
