#!/usr/bin/python3
"""
User class
"""

class User():
    """ User class """

    def __init__(self):
        """ Init """
        self.__password = None

    @property
    def password(self):
        """ Getter for password """
        return self.__password

    @password.setter
    def password(self, value):
        """ Setter for password """
        if type(value) is not str:
            raise TypeError("password must be a string")
        self.__password = value

    def is_valid_password(self, pwd):
        """ Check if pwd is the right password """
        if pwd is None or type(pwd) is not str:
            return False
        return pwd == self.__password


if __name__ == "__main__":
    print("Test User")
    user = User()
    user.password = "root"
    if not user.is_valid_password("root"):
        print("is_valid_password should return True if it's the right password")
