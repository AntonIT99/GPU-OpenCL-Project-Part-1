#!/gnuplot

set term windows 0
plot	'worksizes.dat' using 1:2 title 'execution time in function of work size' with linespoints ls 1 linetype rgb "blue"
set term windows 1
plot	'arraysizes.dat' using 1:2 title 'execution time in function of array size' with linespoints ls 1 linetype rgb "red"
