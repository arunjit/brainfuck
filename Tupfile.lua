-- Tuprules.lua

function compile(source, output)
  tup.definerule{ inputs = {source}, command = 'clang ' .. source .. ' -o ' .. output, outputs = {output} }
end

compile('brainfuck.c', 'build/brainfuck')
