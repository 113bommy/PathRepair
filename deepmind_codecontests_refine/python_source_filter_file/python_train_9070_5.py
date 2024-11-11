def main():
    x= input().split()
    w1= int(x[0])
    h1= int(x[1])
    w2= int(x[2])
    h2= int(x[3])
    green = 0
    if w1 == w2:
        green += ((h1+h2)*4) + 4
    else:
        green += (2*(w1+h1))+(2*(w2+h2))-(2*w2)+5
    print(green)




if __name__ == '__main__':main()