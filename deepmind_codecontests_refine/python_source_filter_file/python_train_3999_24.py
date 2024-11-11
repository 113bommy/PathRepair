from sys import stdin

def main():
    n = int(stdin.readline()) - 1
    count = 0
    prev_s = (stdin.readline())
    while n > 0:
        s = (stdin.readline())
        if prev_s != s:
            count += 1
        prev_s = s
        n -= 1
    print(count)
        
main()