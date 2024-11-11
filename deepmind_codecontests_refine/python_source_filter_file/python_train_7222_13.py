#!/usr/bin/env python3

def main():
    
    from sys import stdin, stdout, stderr
    
    tb = [list(line[:-1]) for line in stdin]
   
    tb = [[[tb[line][i:i+2], tb[lineb][i:i+2]] for i in range(0, 4, 2)] for line, lineb in zip(range(4), range(1,4))] 
    
    for frame in tb:
        for subframe in frame:
            cnta = sum(map(lambda x: x.count('.'), subframe))
            cntb = sum(map(lambda x: x.count('#'), subframe))
            if cnta == 1 or cnta == 0 or cntb == 1 or cntb == 0:
                stdout.write('YES\n')
                return

    stdout.write("NO\n")
    
if __name__ == "__main__":
    main()

