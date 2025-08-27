from ortools.linear_solver import pywraplp # pyright: ignore[reportMissingImports]
solver = pywraplp.Solver.CreateSolver('GLOP')

inp = open("input.txt",'r')
op =  open("output.txt",'w')

op.write(inp.read())