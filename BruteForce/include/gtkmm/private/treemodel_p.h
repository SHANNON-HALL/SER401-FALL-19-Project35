// Generated by gmmproc 2.54.0 -- DO NOT MODIFY!
#ifndef _GTKMM_TREEMODEL_P_H
#define _GTKMM_TREEMODEL_P_H


#include <glibmm/private/interface_p.h>

#include <glibmm/private/interface_p.h>

namespace Gtk
{

class TreeModel_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = TreeModel;
  using BaseObjectType = GtkTreeModel;
  using BaseClassType = GtkTreeModelIface;
  using CppClassParent = Glib::Interface_Class;

  friend class TreeModel;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void row_changed_callback(GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1);
  static void row_inserted_callback(GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1);
  static void row_has_child_toggled_callback(GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1);
  static void row_deleted_callback(GtkTreeModel* self, GtkTreePath* p0);
  static void rows_reordered_callback(GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1, gint* p2);

  //Callbacks (virtual functions):
  static GtkTreeModelFlags get_flags_vfunc_callback(GtkTreeModel* self);
  static gint get_n_columns_vfunc_callback(GtkTreeModel* self);
  static GType get_column_type_vfunc_callback(GtkTreeModel* self, gint index);
    static gboolean iter_next_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
    static gboolean get_iter_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreePath* path);
    static gboolean iter_children_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* parent);
    static gboolean iter_parent_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* child);
    static gboolean iter_nth_child_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, GtkTreeIter* parent, int n);
    static int iter_n_children_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
    static gboolean iter_has_child_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
  static void ref_node_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
  static void unref_node_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
  static GtkTreePath* get_path_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter);
  static void get_value_vfunc_callback(GtkTreeModel* self, GtkTreeIter* iter, gint column, GValue* value);
};


} // namespace Gtk


#endif /* _GTKMM_TREEMODEL_P_H */

