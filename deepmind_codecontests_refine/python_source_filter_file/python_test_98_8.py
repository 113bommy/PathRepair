T = int(input())


def main(keyboard,string):
    if len(string) == 0:
        return 0
    
    dictionary = {}
    position = 1
    for char in keyboard:
        dictionary[char] = position
        position+=1
    
    print(dictionary)
    
    cost = 0
    initial_pos = dictionary[string[0]]
    for i in range(1,len(string)):
        next_pos = dictionary[string[i]]
        cost = cost + abs(next_pos-initial_pos)
        print(next_pos,initial_pos)
        initial_pos = next_pos
        
    return cost
        
        
        



for _ in range(T):
    keyboard = input().strip()
    string = input().strip()
    
    
    print(main(keyboard,string))