HAPPY_END  =     0
NON_HAPPY_END =       -2 
DELTA =          1



def main(a):
    for i in range(a):
        check_string()


def check_string():
    length = int(input())
    s = input()
    if (ispol(s, length) == HAPPY_END):
        print("Yes")
    else:
        print("No")

def ispol(s, length):
    for i in range(length//2):
       diff = abs(ord(s[i]) - ord(s[length - i - 1]))
       if diff and diff != 2*DELTA:
           return NON_HAPPY_END
    return HAPPY_END

if __name__ == "__main__":
    num = int(input())
    main(num)
