from node import Node
from book import Book

class BinarySearchTree:
    def __init__(self) -> None:
        self._root:Node | None = None

    def search(self,isbn:str) -> Node | None:
        return self._search(self._root,isbn)

    def _search(self,root:Node,isbn:str) -> Node | None:
        current = root
        while current:
            if current.book.isbn == isbn: return current
            if isbn > current.book.isbn: current = current.right
            elif isbn < current.book.isbn: current = current.left

        raise(ValueError("non-existent value"))

    def find_Min(self,root:Node) -> Node | None:
        if root is None: return None

        current:Node = root
        while current.left: current = current.left

        return current

    def insert(self,book:Book) -> Node:
        self._root = self._insert(self._root,book)
        return self._root

    def _insert(self,root:Node,book:Book) -> Node:
        new_book = Node(book)
        if root is None: return new_book
        parent = None
        current = root
        while current:
            parent = current
            if book.isbn > current.book.isbn: current = current.right
            elif book.isbn < current.book.isbn: current = current.left
            else: raise(ValueError("Duplicate Value"))
        
        if book.isbn > parent.book.isbn: parent.right = new_book
        else: parent.left = new_book

        return root
    
    def delete(self,isbn:str) -> Node | None:
        self._root = self._delete(self._root,isbn)
        return self._root

    def _delete(self,root:Node,isbn:str) -> Node | None:
        if root is None: return root
        if isbn > root.book.isbn: root.right = self._delete(root.right,isbn)
        elif isbn < root.book.isbn: root.left = self._delete(root.left,isbn)
        else:
            if root.left is None and root.right is None: return None
            elif root.left is None or root.right is None:
                temp = None
                if root.left is None: temp = root.right
                else: temp = root.left
                return temp
            else:
                temp = self.find_Min(root.right)
                root.book = temp.book
                root.right = self._delete(root.right,temp.book.isbn)
        return root
    
    def inOrder(self) -> list | None:
         return self._inOrder(self._root)

    def _inOrder(self,root:Node) -> list | None:
        if root is None: return None

        current:Node = root
        stack:list = []
        data:list = []

        while current or stack:
            while current:
                stack.append(current)
                current = current.left
            
            current = stack.pop()
            data.append(current)
            current = current.right
        
        return data

"""            
if __name__ == "__main__":
    tree = BinarySearchTree()
    book01 = Book("1984","GW","ED",1950,"978-85-359-0277-8")
    book02 = Book("Um diario de um Banana","NM01","ED1",1960,"978-3-16-148410-0")
    book03 = Book("As aventuras de Gulliver","NM02","ED2",1970,"978-85-359-0277-34")
    book04 = Book("Alice no País das Maravilha","NM03","ED2",1980,"978-65-553-201-21")
    book05 = Book("Clean Code","NM04","ED4",1990,"979-10-90636-07-0")
    tree.insert_book(book01)
    tree.insert_book(book02)
    tree.insert_book(book03)
    tree.insert_book(book04)    
    tree.insert_book(book05)
    data = tree.inOrder()
    for i in data: print(i.book.title)
"""