n = int(input())
a = [input()[0:0] + input() for _ in range(n)]
print('\n'.join(['YES' if i.find('8') != -1 and len(i) - i.find('8') > 11
                 else 'NO' for i in a]))
