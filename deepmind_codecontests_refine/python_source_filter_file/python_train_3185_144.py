def yearCalculation(a , b):
    c = 0
    while a < b :
        a = a * 3
        b = b * 2
        c = c + 1
    return c
if __name__ == "__main__":
    x , y = input().split()
    print(yearCalculation(int(x) , int(y)))