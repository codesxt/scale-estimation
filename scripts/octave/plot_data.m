% To run from build/ execute:
% octave --persist ../scripts/octave/plot_data.m

clear;

filename = '../data/data.csv';
data = csvread(filename);

subplot(2,2,1)
plot(data(:,1), data(:,2), '--k', 'linewidth', 5);
title('Real height');
xlabel('Time [s]');
ylabel('Height [m]');

subplot(2,2,2)
plot(data(:,1), data(:,3), '-r', 'linewidth', 1);
title('Sensor Measurements');
xlabel('Time [s]');
ylabel('Height [m]');

subplot(2,2,3)
plot(data(:,1), data(:,4), '-b', 'linewidth', 1);
title('Visual Measurements');
xlabel('Time [s]');
ylabel('Height [m]');

subplot(2,2,4)
hold on;
plot(data(:,1), data(:,3), '-r', 'linewidth', 1);
plot(data(:,1), data(:,4), '-b', 'linewidth', 1);
plot(data(:,1), data(:,2), '--k', 'linewidth', 5);
xlabel('Time [s]');
ylabel('Height [m]');
hold off;
