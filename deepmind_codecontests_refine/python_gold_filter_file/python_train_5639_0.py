def min_capacity(numStops,entry,exit):
    cur_load = entry[0];
    min_load = cur_load;
    for i in range(1,numStops):
        cur_load= cur_load - exit[i]+entry[i];
        if cur_load>min_load:
            min_load = cur_load;
    print(min_load);
    return;
    
def read_line():
    numStops=int(input());
    exit=[];
    entry=[];
    for i in range(numStops):
        a,b=input().split();
        exit.append(int(a));
        entry.append(int(b));
    return numStops,entry,exit;


if __name__=='__main__':
    numStops,entry,exit = read_line();
    min_capacity(numStops,entry,exit);