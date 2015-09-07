% To run from build/ execute:
% octave --persist ../scripts/octave/plot_data.m

clear;

filename = '../data/data.csv';
data = csvread(filename);
filename = '../data/sample_pairs.csv';
samples = csvread(filename);

figure(1)
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

figure(2)
hold on;
plot(data(:,1), data(:,3), '-r', 'linewidth', 1);
plot(data(:,1), data(:,4), '-b', 'linewidth', 1);
plot(data(:,1), data(:,2), '--k', 'linewidth', 5);
legend('Metric Sensor', 'Visual Sensor', 'Real Height');
xlabel('Time [s]');
ylabel('Height [m]');
hold off;

figure(3)
subplot(2,2,1)
plot(samples(:,1), samples(:,3), '-r');
title('Metric sensor samples (x)')
xlabel('Time [s]');
ylabel('Height [m]');

subplot(2,2,2)
plot(samples(:,1), samples(:,2), '-b');
title('Visual sensor samples (x)')
xlabel('Time [s]');
ylabel('Height [m]');

subplot(2,2,3)
hold on;
plot(samples(:,1), samples(:,3), '-r');
plot(samples(:,1), samples(:,2), '-b');
legend('y', 'x');
title('Visual an metric sample pairs')
xlabel('Time [s]');
ylabel('Height [m]');
hold off;

%subplot(2,2,4)
%hold on;
%plot(samples(:,1), samples(:,3), '-r');
%plot(data(:,1), data(:,3), '-b', 'linewidth', 1);
%legend('Metric Samples', 'Metric Sensor')
%xlabel('Time [s]');
%ylabel('Height [m]');
%hold off;
