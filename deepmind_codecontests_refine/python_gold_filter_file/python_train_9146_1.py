instr = input()
for i in range(len(instr)-4):
    if instr[i:i+5] == "apple": instr = instr[:i]+"peach"+instr[i+5:]
    elif instr[i:i+5] == "peach":instr = instr[:i]+"apple"+instr[i+5:]
print(instr)