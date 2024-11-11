import atexit
import io
import sys

# Buffering IO
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
    

def main():
    n = int(input())
    s = []
    for i in range(4):
        df = 0
        for k in range(n):
            l = input()
            for j in range(n):
                if int(l[j]) == (k + j) % 2:
                    df += 1
        if i <3 :
            input()
        s.append(df)
    
    print( min(s[0] + s[1] + n*n-s[2] + n*n-s[3],
        s[0] + s[2] + n*n-s[1] + n*n-s[3],
        s[0] + s[3] + n*n-s[1] + n*n-s[2],
        s[1] + s[2] + n*n-s[0] + n*n-s[3],
        s[1] + s[3] + n*n-s[0] + n*n-s[2],
        s[2] + s[3] + n*n-s[0] + n*n-s[3]))
        
        
    
    
    

    
if __name__ == '__main__':
    main()
        