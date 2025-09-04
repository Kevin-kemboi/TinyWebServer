// This version is simplified to work with online compilers like replit.com or onlinegdb.com
// Copy this code to an online C compiler to test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simplified version for demonstration
int main() {
    printf("=== TINY WEB SERVER SIMULATION ===\n\n");
    
    // Simulate server startup
    printf("🚀 Server starting up...\n");
    printf("📡 Binding to port 8080...\n");
    printf("👂 Listening for connections...\n");
    printf("✅ Server ready!\n\n");
    
    // Simulate HTTP request/response
    printf("=== SIMULATED CLIENT REQUEST ===\n");
    printf("GET / HTTP/1.1\n");
    printf("Host: localhost:8080\n");
    printf("User-Agent: Mozilla/5.0\n\n");
    
    printf("=== SERVER RESPONSE ===\n");
    printf("HTTP/1.1 200 OK\n");
    printf("Content-Type: text/html\n\n");
    
    // Read and display the HTML content that would be served
    printf("=== HTML CONTENT SERVED ===\n");
    FILE *html_file = fopen("index.html", "r");
    if (html_file != NULL) {
        char ch;
        while ((ch = fgetc(html_file)) != EOF) {
            putchar(ch);
        }
        fclose(html_file);
    } else {
        printf("<!DOCTYPE html>\n");
        printf("<html lang=\"en\">\n");
        printf("<head>\n");
        printf("    <meta charset=\"UTF-8\">\n");
        printf("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
        printf("    <title>Simple Web Server</title>\n");
        printf("</head>\n");
        printf("<body>\n");
        printf("    <h1>Hello, World!</h1>\n");
        printf("    <p>This is a simple web server written in C.</p>\n");
        printf("</body>\n");
        printf("</html>\n");
    }
    
    printf("\n\n=== SIMULATION COMPLETE ===\n");
    printf("💡 In a real scenario:\n");
    printf("   • The server would bind to a network socket\n");
    printf("   • Accept incoming TCP connections\n");
    printf("   • Parse HTTP requests\n");
    printf("   • Send HTTP responses\n");
    printf("   • Run continuously until stopped\n");
    
    return 0;
}
