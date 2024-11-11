def solve(s):
    if(min(s.count('0'),s.count('1'))&1):
        return True
    else:
        return False
    

def main():
    for _ in range(int(input())):
        s=str(input())
        if(solve(s)):
            print("DA")
        else:
            print("NET")
if __name__=="__main__":
    main()
