import sys
#input = sys.stdin.readline

def main():
    s = input()
    l = len(s)
    for i in range(l-1):
        if s[i] == s[i+1]:
            print(i+1,i+2)
            exit()
    
    for i in range(l-2):
        if s[i] == s[i+2]:
            print(i+1,1+3)
            exit()
    
    print(-1,-1)

if __name__ == "__main__":
    main()
