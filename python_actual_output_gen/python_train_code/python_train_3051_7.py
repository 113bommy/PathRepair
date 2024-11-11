def program():
   a,b,c,d=[int(x) for x in input().split()]
   print(a+b)
if __name__ == "__main__":
    number_of_testcases = int(input())
    for i in range(number_of_testcases):
        program()
        print()