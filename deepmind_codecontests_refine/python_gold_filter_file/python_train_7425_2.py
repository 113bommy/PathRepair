def process():
    n = int(input())
    path = []
    
    for _ in range(n):
        cmd = input()
        if cmd == 'pwd':
            print(f'/{"/".join(path)}/' if path else '/')
        else:
            cmd = cmd[3:].split('/')
            for c in cmd:
                if c == '':
                    path = []
                elif c == '..':
                    path.pop()
                else:
                    path.append(c)
                    
process()