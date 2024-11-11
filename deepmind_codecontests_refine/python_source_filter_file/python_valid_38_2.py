from sys import stdin, stdout
"""
 ____  __.        .__                         
|    |/ _|_____   |  |  ___.__. __ __   ____  
|      <  \__  \  |  | <   |  ||  |  \ / ___\ 
|    |  \  / __ \_|  |__\___  ||  |  // /_/  >
|____|__ \(____  /|____// ____||____/ \___  / 
        \/     \/       \/           /_____/ 
"""
for _ in range(int(stdin.readline())):

    n = int(stdin.readline())
    
    n = max(n,6)
    n += 1

    print(int(n * 2.5))