def main():
    from random import choice
    n,k = input().split()
    n = int(n)
    k = int(k)
    abjad = 'abcdefghijklmnopqrstuvwxyz'
    string = ''
    j = 0
    data = []
    while len(data) < k:
        j = choice(abjad)
        if j not in data:
            string += j
            data.append(j)
    if len(data) == n:
        print(string)
    else:
        j = 0
        while len(string) <= n:
            if j < len(data):
                string += data[j]
                j += 1
            else:
                j = 0 
        print(string)
    
        
    
main()