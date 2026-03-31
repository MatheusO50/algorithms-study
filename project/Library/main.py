from bst import BinarySearchTree
from book import Book
from node import Node

tree = BinarySearchTree()

def menu():
    print("""

    ===============Library===============

        [1]-Register Book
        [2]-Search Book
        [3]-Delete Book
        [4]-Registered Books
        [0]-Exit

    ======================================    """)

def register_book():
    while True:
        try:
            name_book:str = str(input("\n\tEnter Book name:...")).strip().lower()
        except ValueError:
            print("Name Book Invalid")
            continue
        try:
            author:str = str(input("\tEnter Book author:...")).strip().lower()
        except ValueError:
            print("Book author Invalid")
            continue
        try:
            publisher:str = str(input("\tEnter Book publisher:...")).strip().lower()
        except ValueError:
            print("Book publisher Invalid")
            continue
        try:
            year:int = int(input("\tEnter year it was released book:..."))
        except ValueError:
            print("Year Invalid")
            continue
        try: 
            isbn:str = str(input("\tEnter the book's ISBN:...")).strip().lower()
            break
        except ValueError:
            print("Book ISBN Invalid")
            continue


    tree.insert(Book(name_book,author,publisher,year,isbn))

def search_book():
    try: isbn:str = str(input("\tEnter the book's ISBN:...")).strip().lower()
    except Exception: raise(Exception)

    book:Node = tree.search(isbn)
    if book is None: 
        print("Book not Found")
        return

    print(f"""
+------------------------------+
|📖 BOOK INFO                  |
+------------------------------+
| NAME      : {book.book.title}             
| Author    : {book.book.author}               
| Publisher : {book.book.publisher}          
| Year      : {book.book.year}               
| ISBN      : {book.book.isbn}              
+------------------------------+
""")

def delete_book():
    try: isbn:str = str(input("\tEnter the book's ISBN:...")).strip().lower()
    except Exception: raise(Exception)

    tree.delete(isbn)
    print("Book successfully deleted")

def All_books():
    data:list = tree.inOrder()

    for book in data: print(book.book.title)

def main():
    function = None
    input_user:int = 0
    options:dict = {
        1 : register_book,
        2 : search_book,
        3 : delete_book,
        4 : All_books
    }

    while True:
        menu()
        input_user = int(input("\n\tEnter one of the options above:..."))
        function = options.get(input_user)

        if function:
            function()
        elif input_user == 0:
            print("Exit Libray") 
            break
        else: print("Invalid Value")
        

main()


