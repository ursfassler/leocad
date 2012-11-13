// Menu Creation.
//

#include "lc_global.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include "typedefs.h"
#include "main.h"
#include "gtkmisc.h"
#include "mainwnd.h"


void create_main_menu (GtkObject *window, GtkWidget *vbox)
{
#include "pixmaps/st-new.xpm"
#include "pixmaps/st-open.xpm"
#include "pixmaps/st-save.xpm"
#include "pixmaps/photo.xpm"
#include "pixmaps/info.xpm"
#include "pixmaps/st-undo.xpm"
#include "pixmaps/st-redo.xpm"
#include "pixmaps/st-cut.xpm"
#include "pixmaps/st-copy.xpm"
#include "pixmaps/st-paste.xpm"

  GtkWidget *handle_box, *menu_bar, *menu, *menu_in_menu, *item;
  GtkAccelGroup *accel;

  accel = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(window), accel);
  handle_box = gtk_handle_box_new ();
  gtk_box_pack_start (GTK_BOX (vbox), handle_box, FALSE, FALSE, 0);
  gtk_widget_show (handle_box);

  menu_bar = gtk_menu_bar_new ();
  gtk_container_add (GTK_CONTAINER (handle_box), menu_bar);
  gtk_widget_show (menu_bar);

  // File menu
  menu = create_sub_menu (menu_bar, "_File", accel);
  menu_tearoff (menu);

  create_pixmap_menu_item (menu, "_New", st_new, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_FILE_NEW, "menu_file_new");
  create_pixmap_menu_item (menu, "_Open...", st_open, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_FILE_OPEN, "menu_file_open");
  create_menu_item (menu, "_Merge...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_MERGE, "menu_file_merge");
  menu_separator (menu);

  create_pixmap_menu_item (menu, "_Save", st_save, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_FILE_SAVE, "menu_file_save");
  create_menu_item (menu, "Save _As...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_SAVEAS, "menu_file_saveas");
  create_pixmap_menu_item (menu, "Save Pic_ture...", photo, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_FILE_PICTURE, "menu_file_picture");

  menu_in_menu = create_menu_in_menu (menu, "Ex_port", accel);
  create_menu_item (menu_in_menu, "_HTML...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_HTML, "menu_file_html");
  create_menu_item (menu_in_menu, "_POV-Ray...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_POVRAY, "menu_file_povray");
  create_menu_item (menu_in_menu, "_Wavefront...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_WAVEFRONT, "menu_file_wavefront");
  menu_separator (menu);

  create_pixmap_menu_item (menu, "Propert_ies...", info, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_FILE_PROPERTIES, "menu_file_properties");
  create_menu_item (menu, "Pieces _Library Manager...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_FILE_LIBRARY, "menu_file_library");
  menu_separator (menu);

  BaseMenuItem base;
  base.accel = accel;

  base.widget = create_menu_item (menu, "1", accel, GTK_SIGNAL_FUNC (OnCommand),
                                  window, ID_FILE_RECENT1, "menu_file_recent1");
  main_window->SetMenuItem (LC_MAINWND_RECENT1, &base);
  base.widget = create_menu_item (menu, "2", accel, GTK_SIGNAL_FUNC (OnCommand),
                                  window, ID_FILE_RECENT2, "menu_file_recent2");
  main_window->SetMenuItem (LC_MAINWND_RECENT2, &base);
  base.widget = create_menu_item (menu, "3", accel, GTK_SIGNAL_FUNC (OnCommand),
                                  window, ID_FILE_RECENT3, "menu_file_recent3");
  main_window->SetMenuItem (LC_MAINWND_RECENT3, &base);
  base.widget = create_menu_item (menu, "4", accel, GTK_SIGNAL_FUNC (OnCommand),
                                  window, ID_FILE_RECENT4, "menu_file_recent4");
  main_window->SetMenuItem (LC_MAINWND_RECENT4, &base);
  gtk_object_set_data (window, "file_menu_accel", accel);

  menu_separator (menu);
  create_menu_item (menu, "E_xit...", accel, GTK_SIGNAL_FUNC (OnCommand),
		    window, ID_FILE_EXIT, "menu_file_exit");

  // Edit menu
  menu = create_sub_menu (menu_bar, "_Edit", accel);
  menu_tearoff (menu);

  create_pixmap_menu_item (menu, "_Undo", st_undo, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_EDIT_UNDO, "menu_edit_undo");
  create_pixmap_menu_item (menu, "_Redo", st_redo, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_EDIT_REDO, "menu_edit_redo");
  menu_separator (menu);

  create_pixmap_menu_item (menu, "Cu_t", st_cut, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_EDIT_CUT, "menu_edit_cut");
  create_pixmap_menu_item (menu, "_Copy", st_copy, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_EDIT_COPY, "menu_edit_copy");
  create_pixmap_menu_item (menu, "_Paste", st_paste, accel, GTK_SIGNAL_FUNC (OnCommandDirect),
                           window, LC_EDIT_PASTE, "menu_edit_paste");
  menu_separator (menu);

  create_menu_item (menu, "Select _All", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_EDIT_SELECT_ALL, "menu_edit_select_all");
  create_menu_item (menu, "Select _None", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_EDIT_SELECT_NONE, "menu_edit_select_none");
  create_menu_item (menu, "Select _Invert", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_EDIT_SELECT_INVERT, "menu_edit_select_invert");
  create_menu_item (menu, "_Select by Name...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_EDIT_SELECT_BYNAME, "menu_edit_select_byname");

  // View menu
  menu = create_sub_menu (menu_bar, "_View", accel);
  menu_tearoff (menu);

  create_menu_item (menu, "_Preferences...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_PREFERENCES, "menu_view_preferences");
  menu_separator (menu);

  create_menu_item (menu, "Zoom _In", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_ZOOMIN, "menu_view_zoomin");
  create_menu_item (menu, "Zoom _Out", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_ZOOMOUT, "menu_view_zoomout");
  create_menu_item (menu, "Zoom E_xtents", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_ZOOMEXTENTS, "menu_view_zoomextents");

  menu_in_menu = create_menu_in_menu (menu, "_Viewpoints", accel);

  create_menu_item (menu_in_menu, "Front", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_FRONT, "menu_view_viewpoint_front");
  create_menu_item (menu_in_menu, "Back", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_BACK, "menu_view_viewpoint_back");
  create_menu_item (menu_in_menu, "Top", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_TOP, "menu_view_viewpoint_top");
  create_menu_item (menu_in_menu, "Bottom", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_BOTTOM, "menu_view_viewpoint_bottom");
  create_menu_item (menu_in_menu, "Left", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_LEFT, "menu_view_viewpoint_left");
  create_menu_item (menu_in_menu, "Right", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_RIGHT, "menu_view_viewpoint_right");
  create_menu_item (menu_in_menu, "Home", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_VIEWPOINT_HOME, "menu_view_viewpoint_home");

  menu_in_menu = create_menu_in_menu (menu, "_Cameras", accel);
  gtk_object_set_data (window, "cameras_menu", menu_in_menu);

  create_menu_item(menu_in_menu, "_Reset", accel, GTK_SIGNAL_FUNC(OnCommandDirect), window, LC_VIEW_CAMERA_RESET, "menu_cameras_reset");

  menu_in_menu = create_menu_in_menu (menu, "S_tep", accel);
  create_menu_item (menu_in_menu, "Fi_rst", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_FIRST, "menu_view_step_first");
  create_menu_item (menu_in_menu, "Pre_vious", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_PREVIOUS, "menu_view_step_previous");
  create_menu_item (menu_in_menu, "Ne_xt", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_NEXT, "menu_view_step_next");
  create_menu_item (menu_in_menu, "_Last", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_LAST, "menu_view_step_last");
  menu_separator (menu_in_menu);
  create_menu_item (menu_in_menu, "_Insert", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_INSERT, "menu_view_step_insert");
  create_menu_item (menu_in_menu, "_Delete", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_VIEW_STEP_DELETE, "menu_view_step_delete");

//  create_menu_item (menu, "_Create", accel, GTK_SIGNAL_FUNC (OnCommand),
//		    window, ID_VIEW_CREATE, "menu_view_create");

  menu_separator (menu);

  menu_in_menu = create_menu_in_menu (menu, "Tool_bars", accel);
  create_check_menu_item (menu_in_menu, "S_tandard", accel, GTK_SIGNAL_FUNC (OnCommand), 
			  window, ID_VIEW_TOOLBAR_STANDARD, "menu_view_toolbar_standard");
  create_check_menu_item (menu_in_menu, "Dra_wing", accel, GTK_SIGNAL_FUNC (OnCommand), 
			  window, ID_VIEW_TOOLBAR_DRAWING, "menu_view_toolbar_drawing");
  create_check_menu_item (menu_in_menu, "Ani_mation", accel, GTK_SIGNAL_FUNC (OnCommand), 
			  window, ID_VIEW_TOOLBAR_ANIMATION, "menu_view_toolbar_animation");
//  create_check_menu_item (menu_in_menu, "Mo_dify", accel, GTK_SIGNAL_FUNC (OnCommand), 
//			  window, ID_VIEW_TOOLBAR_MODIFY, "menu_view_toolbar_modify");
  create_check_menu_item (menu_in_menu, "_Pieces", accel, GTK_SIGNAL_FUNC (OnCommand), 
			  window, ID_VIEW_TOOLBAR_PIECES, "menu_view_toolbar_pieces");
  menu_separator (menu_in_menu);
  create_check_menu_item (menu_in_menu, "_Floating Pieces", accel, GTK_SIGNAL_FUNC (OnCommand), 
			  window, ID_VIEW_TOOLBAR_FLOATING, "menu_view_toolbar_floating");
  item = create_radio_menu_item (menu_in_menu, NULL, "Icons _and Text", accel,
				 GTK_SIGNAL_FUNC (OnCommand), window,
				 ID_VIEW_TOOLBAR_BOTH, "menu_view_toolbar_both");
  item = create_radio_menu_item (menu_in_menu, item, "_Icons only", accel,
				 GTK_SIGNAL_FUNC (OnCommand), window,
				 ID_VIEW_TOOLBAR_ICONS, "menu_view_toolbar_icons");
  item = create_radio_menu_item (menu_in_menu, item, "Te_xt only", accel,
				 GTK_SIGNAL_FUNC (OnCommand), window,
				 ID_VIEW_TOOLBAR_TEXT, "menu_view_toolbar_text");

  // Piece menu
  menu = create_sub_menu (menu_bar, "_Piece", accel);
  menu_tearoff (menu);

  create_menu_item (menu, "_Insert", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_INSERT, "menu_piece_insert");
  create_menu_item (menu, "De_lete", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_DELETE, "menu_piece_delete");
  create_menu_item (menu, "Ar_ray...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_ARRAY, "menu_piece_array");
  create_menu_item (menu, "Minifig Wi_zard...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_MINIFIG, "menu_piece_minifig");
  create_menu_item (menu, "_Copy Keys", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_COPYKEYS, "menu_piece_copykeys");
  menu_separator (menu);

  create_menu_item (menu, "_Group", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_GROUP, "menu_piece_group");
  create_menu_item (menu, "_Ungroup", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_UNGROUP, "menu_piece_ungroup");
  create_menu_item (menu, "Re_move from Group", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_GROUP_REMOVE, "menu_piece_group_remove");
  create_menu_item (menu, "A_dd to Group", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_GROUP_ADD, "menu_piece_group_add");
  create_menu_item (menu, "Edi_t Groups...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_GROUP_EDIT, "menu_piece_group_edit");
  menu_separator (menu);
  
  create_menu_item (menu, "Hide _Selected", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_HIDE_SELECTED, "menu_piece_hide_selected");
  create_menu_item (menu, "Hide U_nselected", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_HIDE_UNSELECTED, "menu_piece_hide_unselected");
  create_menu_item (menu, "Unhide _All", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_PIECE_UNHIDE_ALL, "menu_piece_unhide_all");

  menu = create_sub_menu (menu_bar, "_Help", accel);
  menu_tearoff (menu);

  create_menu_item (menu, "_About...", accel, GTK_SIGNAL_FUNC (OnCommandDirect),
		    window, LC_HELP_ABOUT, "menu_help_about");

  // TODO: read accelerators from a file
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_file_new"));
  gtk_widget_add_accelerator (item, "activate", accel, 'N', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_file_open"));
  gtk_widget_add_accelerator (item, "activate", accel, 'O', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_file_save"));
  gtk_widget_add_accelerator (item, "activate", accel, 'S', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_file_exit"));
  gtk_widget_add_accelerator (item, "activate", accel, 'Q', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_edit_undo"));
  gtk_widget_add_accelerator (item, "activate", accel, 'Z', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_edit_redo"));
  gtk_widget_add_accelerator (item, "activate", accel, 'Y', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_edit_cut"));
  gtk_widget_add_accelerator (item, "activate", accel, 'X', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_edit_copy"));
  gtk_widget_add_accelerator (item, "activate", accel, 'C', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_edit_paste"));
  gtk_widget_add_accelerator (item, "activate", accel, 'V', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_piece_array"));
  gtk_widget_add_accelerator (item, "activate", accel, 'R', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_piece_group"));
  gtk_widget_add_accelerator (item, "activate", accel, 'G', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_piece_ungroup"));
  gtk_widget_add_accelerator (item, "activate", accel, 'U', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_piece_group_remove"));
  gtk_widget_add_accelerator (item, "activate", accel, 'M', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  item = GTK_WIDGET (gtk_object_get_data (window, "menu_piece_group_add"));
  gtk_widget_add_accelerator (item, "activate", accel, 'D', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
}

GtkWidget* create_snap_menu()
{
	GtkWidget* menu;
	GtkWidget* menu_item;

	menu = gtk_menu_new();

	menu_item = gtk_check_menu_item_new_with_mnemonic("Snap _X");
	gtk_object_set_data(GTK_OBJECT(menu), "snap_x", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_SNAP_X));
	gtk_widget_show(menu_item);

	menu_item = gtk_check_menu_item_new_with_mnemonic("Snap _Y");
	gtk_object_set_data(GTK_OBJECT(menu), "snap_y", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_SNAP_Y));
	gtk_widget_show(menu_item);

	menu_item = gtk_check_menu_item_new_with_mnemonic("Snap _Z");
	gtk_object_set_data(GTK_OBJECT(menu), "snap_z", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_SNAP_Z));
	gtk_widget_show(menu_item);

	menu_item = gtk_menu_item_new_with_mnemonic("Snap _None");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_SNAP_NONE));
	gtk_widget_show(menu_item);

	menu_item = gtk_menu_item_new_with_mnemonic("Snap _All");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_SNAP_ALL));
	gtk_widget_show(menu_item);

	return menu;
}

GtkWidget* create_lock_menu()
{
	GtkWidget* menu;
	GtkWidget* menu_item;

	menu = gtk_menu_new();

	menu_item = gtk_check_menu_item_new_with_mnemonic("Lock _X");
	gtk_object_set_data(GTK_OBJECT(menu), "lock_x", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_LOCK_X));
	gtk_widget_show(menu_item);

	menu_item = gtk_check_menu_item_new_with_mnemonic("Lock _Y");
	gtk_object_set_data(GTK_OBJECT(menu), "lock_y", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_LOCK_Y));
	gtk_widget_show(menu_item);

	menu_item = gtk_check_menu_item_new_with_mnemonic("Lock _Z");
	gtk_object_set_data(GTK_OBJECT(menu), "lock_z", menu_item);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_LOCK_Z));
	gtk_widget_show(menu_item);

	menu_item = gtk_menu_item_new_with_mnemonic("Unlock All");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
	gtk_signal_connect(GTK_OBJECT(menu_item), "activate", GTK_SIGNAL_FUNC(OnCommand),
	                   GINT_TO_POINTER(ID_LOCK_NONE));
	gtk_widget_show(menu_item);

	return menu;
}

