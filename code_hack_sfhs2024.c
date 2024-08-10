#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  
#include <time.h>    


#define SUSPICIOUS_THRESHOLD 3
#define IP_ADDRESS_SIZE 50


int check_firewall(const char* device_id, const char* ip_address, int port) {
    
    return 0; 
}


void generate_random_ip(char* ip_address, size_t size) {
    snprintf(ip_address, size, "192.168.1.%d", rand() % 256);
}


int detect_suspicious_activity(int attempts) {
    return attempts > SUSPICIOUS_THRESHOLD;
}


void notify_admin(const char* ip_address) {
    printf("ALERT: Suspicious activity detected from IP Address: %s\n", ip_address);
}


void block_connection(const char* ip_address) {
    printf("BLOCKING CONNECTION for IP Address: %s\n", ip_address);
}

int main() {
    char device_id[100];
    char ip_address[IP_ADDRESS_SIZE];
    int port;
    int attempts = 0;
    int max_attempts = 5; 
    int seconds = 5;       

    
    srand((unsigned int)time(NULL));

    printf("Enter Smart Bulb Device ID: ");
    fgets(device_id, sizeof(device_id), stdin);
  
    device_id[strcspn(device_id, "\n")] = '\0';
    
    printf("Enter Port Number: ");
    scanf("%d", &port);

    while (1) {
        
        generate_random_ip(ip_address, sizeof(ip_address));

        printf("\nSimulating Firewall Detection...\n");
        printf("Device ID: %s\n", device_id);
        printf("IP Address: %s\n", ip_address);
        printf("Port: %d\n", port);

      
        if (check_firewall(device_id, ip_address, port)) {
            printf("Smart Bulb Passed Through Firewall.\n");
        } else {
            printf("Smart Bulb Blocked by Firewall.\n");
            notify_admin(ip_address);
            block_connection(ip_address);
            attempts = 0;  
        }

        
        if (detect_suspicious_activity(attempts)) {
            notify_admin(ip_address);
            block_connection(ip_address);
            attempts = 0;  
        } else {
            printf("No suspicious activity detected.\n");
            attempts++;
        }

        
        sleep(seconds); 
    }

    return 0;
}


