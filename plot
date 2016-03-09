set title 'my plot'
set xlabel 'x axis'
set ylabel 'y axis'
set terminal png
set output 'output_plot.png'
plot [1:10][0:1] sin(x)