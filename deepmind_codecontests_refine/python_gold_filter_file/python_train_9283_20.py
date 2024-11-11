import sys 
def main():
    n = int(input())
    if n==1:
        print("YES")
        print("1 2")
        sys.exit()
    elif n% 2 ==0 :
        print("NO")
        sys.exit()     
    elif n ==3:
        print("YES")
        print("1 4 5 2 3 6")
    else:    
        print("YES")
        print("1 4 5", end = '')
        for i in range(int((n-3)/2)):
            print(f" {4*i+8}" , end = '')
            print(f" {4*i+9}" , end = '')
        print(" 2 3 6", end = '')
        for i in range(int((n-3)/2)):
            print(f" {4*i+7}" , end = '')
            print(f" {4*i+10}" , end = '')



def output(somelist):
    output =""
    for j in somelist:
        output =output +  str(j) + " "
    return output[:-1]


if __name__ == "__main__": main()