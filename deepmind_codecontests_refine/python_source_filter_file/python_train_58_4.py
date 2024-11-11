def main():
  numberOfCommands, totalMemory = map(int, input().split())
  #I will mark erase operation with a negative number, in order to differenceate it from alloc
  #also the defragment will be marked with 0, as we don't have any alloc or erase with 0
  operations = []
  memory = [0]*totalMemory
  for _ in range(numberOfCommands):
    inputOperation = input().split()
    if inputOperation[0] == 'alloc':
      operations.append(int(inputOperation[1]))
    elif inputOperation[0] == 'erase':
      if int(inputOperation[1]) < 0:
        operations.append(-100000000000000000) 
      else:
        operations.append(-int(inputOperation[1])) 
    else:
      operations.append(0)
  allocNumber = 1
  for operation in operations:
    if operation > 0:
      i = 0
      consecutiveEmpty = 0
      while i < len(memory):
        if memory[i] == 0:
          consecutiveEmpty += 1
          if consecutiveEmpty == operation:
            break
        else:
          consecutiveEmpty = 0
        i += 1
      if consecutiveEmpty == operation:
        while consecutiveEmpty - 1 >= 0:
          memory[i - consecutiveEmpty + 1] = allocNumber
          consecutiveEmpty -= 1
        print(allocNumber)
        allocNumber += 1
      else:
        print('NULL')

    elif operation < 0:
      if abs(operation) in memory:
        memory = list(map(lambda bit: bit if bit != abs(operation) else 0, memory))
      else:
        print('ILLEGAL_ERASE_ARGUMENT')
    elif operation == 0:
      while 0 in memory:
        memory.remove(0)
      while len(memory) < totalMemory:
        memory.append(0)

main()