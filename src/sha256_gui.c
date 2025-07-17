// src/sha256_gui.c
#include "sha256_gui.h"
#include "utils.h"
#include <gtk/gtk.h>
#include <openssl/sha.h> // for SHA256_DIGEST_LENGTh and SHA256 functions
#include <stdio.h>
#include <string.h>

// GTK Widgets
GtkWidget *input_entry;
GtkWidget *output_label;

// Callback function for the intput changes
void on_input_changed(GtkEditable *editable, gpointer user_data) {
  const char *input_text = gtk_entry_get_text(GTK_ENTRY(input_entry));
  unsigned char hash[SHA256_DIGEST_LENGTH];
  char hash_hex[SHA256_DIGEST_LENGTH * 2 + 1]; // +1 for null terminator

  if (strlen(input_text) > 0) {
    SHA256((const unsigned char *)input_text, strlen(input_text), hash);
    bytes_to_hex_string(hash, SHA256_DIGEST_LENGTH, hash_hex);
    gtk_label_set_text(GTK_LABEL(output_label), hash_hex);
  } else {
    gtk_label_set_text(GTK_LABEL(output_label),
                       "Enter text to calculate SHA-256 hash");
  }
}

// Function to create and run the GTK application
static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *vbox;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Real-time SHA-256 Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10); // 10px spacing
  gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  // Input Entry
  input_entry = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(input_entry),
                                 "Type or paste text here...");
  g_signal_connect(input_entry, "changed", G_CALLBACK(on_input_changed), NULL);
  gtk_box_pack_start(GTK_BOX(vbox), input_entry, FALSE, FALSE, 0);

  // Output Label
  output_label = gtk_label_new("Enter text to calculate SHA-256");
  gtk_label_set_line_wrap(GTK_LABEL(output_label), TRUE);
  gtk_label_set_selectable(GTK_LABEL(output_label),
                           TRUE); // Allow copying the hash
  gtk_box_pack_start(GTK_BOX(vbox), output_label, TRUE, TRUE,
                     0); // Expand to fill space

  gtk_widget_show_all(window);
}

// Function to run the GTK application
int run_sha256_gui(int argc, char *argv[]) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("com.example.sha256calculator",
                            G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
