
/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "interface.h"
#include "support.h"
#include "callbacks.h"

char *hydra_path1 = "/usr/bin/hydra";
char *hydra_path2 = "/usr/local/bin/hydra";
char *hydra_path3 = "./hydra";


int main(int argc, char *argv[]) {
  extern GtkWidget *wndMain;
  int i;
  extern guint message_id;
  GtkWidget *output;
  GtkTextBuffer *outputbuf;

  gtk_set_locale();
  gtk_init(&argc, &argv);

  add_pixmap_directory(PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /* initialize the message id */
  message_id = 0;

  /* locate the hydra binary */
  HYDRA_BIN = NULL;
  for (i = 0; i < argc - 1; i++) {
    if (!strcmp(argv[i], "--hydra-path")) {
      HYDRA_BIN = argv[i + 1];
      break;
    }
  }

  if ((HYDRA_BIN != NULL) && (g_file_test(HYDRA_BIN, G_FILE_TEST_IS_EXECUTABLE))) {
    /* just for obfuscation *g* */
  } else if (g_file_test(hydra_path1, G_FILE_TEST_IS_EXECUTABLE)) {
    HYDRA_BIN = hydra_path1;
  } else if (g_file_test(hydra_path2, G_FILE_TEST_IS_EXECUTABLE)) {
    HYDRA_BIN = hydra_path2;
  } else if (g_file_test(hydra_path3, G_FILE_TEST_IS_EXECUTABLE)) {
    HYDRA_BIN = hydra_path3;
  } else {
    g_error("Please tell me where hydra is, use --hydra-path\n");
    return -1;
  }

  /* create window and show it */
  wndMain = create_wndMain();
  gtk_widget_show(wndMain);


  /* if we cant use the new cool file chooser, the save button gets disabled */
#ifndef GTK_TYPE_FILE_CHOOSER
  GtkWidget *btnSave;

  btnSave = lookup_widget(GTK_WIDGET(wndMain), "btnSave");
  gtk_widget_set_sensitive(btnSave, FALSE);
#endif


  /* update the statusbar every now and then */
  g_timeout_add(600, update_statusbar, NULL);

  /* we want bold text in the output window */
  output = lookup_widget(GTK_WIDGET(wndMain), "txtOutput");
  outputbuf = gtk_text_view_get_buffer((GtkTextView *) output);
  gtk_text_buffer_create_tag(outputbuf, "bold", "weight", PANGO_WEIGHT_BOLD, NULL);

  /* he ho, lets go! */
  gtk_main();
  return 0;
}
