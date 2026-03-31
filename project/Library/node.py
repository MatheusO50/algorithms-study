from book import Book

class Node:
    def __init__(self,book:Book) -> None:
        self.book = book
        self.left = self.right = None